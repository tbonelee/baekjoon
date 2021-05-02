#include <stdio.h>

int N;
int arr[500001];
int M;
int arr2[500001];
int retarr[500001];
void	only_merge(int arr[], int left, int mid, int right);

void	merge_sort(int arr[], int left, int right);

void	bin_search(int tosearch, int start, int end, int i);

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
		bin_search(arr2[i], 1, N, i);
	}
		// if (bin_search(arr2[i], 1, M) == 1)
		// 	ret++;
	for (int i = 1; i <= M; i++)
		printf("%d ", retarr[i]);
	printf("\n");
}


void	bin_search(int tosearch, int start, int end, int i)
{

	if (tosearch < arr[1] || tosearch > arr[N])
		return ;

	while (1)
	{

		if (start >= end)
		{
			if (tosearch == arr[start])
				retarr[i]++;
			return ;
		}
		int mid = (start + end) / 2;
		if (tosearch == arr[mid])
		{
			// retarr[i]++;
			int ileft = mid - 1;
			for (; ileft >= start && arr[ileft] == tosearch; ileft--)
				;
			int iright = mid + 1;
			for (; iright <= end && arr[iright] == tosearch; iright++)
				;
			retarr[i] = iright - ileft - 1;
			return;
		}
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
