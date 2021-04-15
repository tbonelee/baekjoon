#include <stdio.h>

int N;
int arr[500001];
int M;
int arr2[500001];
int left[500001];
int right[500001];
void	only_merge(int arr[], int left, int mid, int right);

void	merge_sort(int arr[], int left, int right);

int	left_search(int tosearch, int start, int end);

int	right_search(int tosearch, int start, int end);
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
		scanf("%d", &arr2[i]);
	merge_sort(arr, 1, N);
	for (int i = 1; i <= M; i++)
	{
		left[i] = left_search(arr2[i], 1, N);
		right[i] = right_search(arr2[i], 1, N);
		// printf("tofind[%d] = %d, left[i] = %d, right[i] = %d\n", i, arr2[i], left[i], right[i]);
	}
		// if (bin_search(arr2[i], 1, M) == 1)
		// 	ret++;
	for (int i = 1; i <= M; i++)
		printf("%d ", (right[i] > left[i] ? right[i] - left[i] : 0));
	printf("\n");
}


int	left_search(int tosearch, int start, int end)
{

	while (start < end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] >= tosearch)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}

int	right_search(int tosearch, int start, int end)
{
	while (start <= end)
	{
		if (start == end)
		{
			if (arr[start] == tosearch)
				start++;
			return start;
		}
		int mid = (start + end) / 2;
		if (arr[mid] > tosearch)
			end = mid;
		else
			start = mid + 1;
	}
	return end; // error 안 뜨게 하는 용도. 어차피 여기 들어오지 않음
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
