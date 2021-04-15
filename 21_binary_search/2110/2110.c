// 우선 주소대로 정렬

// 가장 왼쪽 주소에는 무조건 설치하는 것이 최선

// 가능한 공유기간 최소 거리는 1, 최대 거리는 오른쪽 끝 주소와 왼쪽 끝 주소의 차이

// 이 둘을 start와 end로 잡고, 새로 공유기를 놓을 때 거리가 mid보다 클 때에만 공유기를 놓는다.

// 공유기 갯수를 세고 목표치보다 크면 start = mid + 1
// 작으면 end = mid - 1

// 목표치보다 클 때에는 공유기를 덜 놓는 것도 가능한 것이므로
// 목표치와 같거나 클 때 출력할 최대 거리를 갱신

#include <stdio.h>

int N, C;
int arr[200000];
void	only_merge(int arr[], int left, int mid, int right);

void	merge_sort(int arr[], int left, int right);
int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	merge_sort(arr, 0, N - 1);
	int start = 1;
	int end = arr[N - 1] - arr[0];
	int max = -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int cnt = 1;
		int latest_pos = arr[0];
		for (int i = 0; i < N; i++)
		{
			if (arr[i] - latest_pos >= mid)
			{
				cnt++; latest_pos = arr[i];
			}
		}
		if (cnt >= C)
		{
			if (mid > max)
				max = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	printf("%d\n", max);
}


void	only_merge(int arr[], int left, int mid, int right)
{
	int temp[right - left + 1];
	int i_left = left;
	int i_right = mid + 1;
	int i_temp = -1;

	for (; i_left <= mid && i_right <= right;)
	{
		if (arr[i_left] < arr[i_right])
			temp[++i_temp] = arr[i_left++];
		else
			temp[++i_temp] = arr[i_right++];
	}

	if (i_left > mid)
		while (i_right <= right)
			temp[++i_temp] = arr[i_right++];
	else
		while (i_left <= mid)
			temp[++i_temp] = arr[i_left++];

	for (i_temp = 0; i_temp < right - left + 1; i_temp++)
		arr[left + i_temp] = temp[i_temp];
}

void	merge_sort(int arr[], int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		only_merge(arr, left, mid, right);
	}
}
