#include <stdio.h>

int N;
int arr[100001];

void	only_merge(int arr[], int left, int mid, int right);

void	merge_sort(int arr[], int left, int right);

int		bin_search(int tosearch, int start, int end);

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	merge_sort(arr, 1, N);
	int M;
	scanf("%d", &M);
	for (int i = 1; i <= M; i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d\n", bin_search(temp, 1, N));

	}
}


int		bin_search(int tosearch, int start, int end)
{

	if (tosearch < arr[1] || tosearch > arr[N])
		return 0;

	while (1)
	{

		if (start >= end)
		{
			if (tosearch == arr[start])
				return 1;
			else
				return 0;
		}
		int mid = (start + end) / 2;
		if (tosearch == arr[mid])
			return 1;
		else if (tosearch > arr[mid])
			start = mid + 1;
		else
			end = mid;
	}
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
