#include <stdio.h>
#include <limits.h>

void	mergesort_des(int arr[], int start, int end);
void	merge_des(int arr[], int start, int mid, int end);

int main()
{
	int N;	scanf("%d", &N);
	int max = 0;
	int arr[100005];
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergesort_des(arr, 1, N);
	for (int i = 1; i <= N; i++)
	{
		// printf("arr[%d] = %d\n", i, arr[i]);
		if (i * arr[i] > max)
		{

			max = i * arr[i];
			// printf("max = %d, i = %d, arr[i] = %d\n", max, i, arr[i]);
		}
	}
	printf("%d\n", max);
	return (0);
}


void	mergesort_des(int arr[], int start, int end)
{
	if (start >= end)
		return ;

	int mid = (start + end) / 2;
	mergesort_des(arr, start, mid);
	mergesort_des(arr, mid + 1, end);
	merge_des(arr, start, mid, end);
}

void	merge_des(int arr[], int start, int mid, int end)
{
	int min = INT_MIN;
	int temp1[100005];
	int temp2[100005];
	int i = start;
	for (; i <= mid; i++)
	{
		temp1[i] = arr[i];
	}
	temp1[i] = min;

	int j = mid + 1;
	for (; j <= end; j++)
	{
		temp2[j] = arr[j];
	}
	temp2[j] = min;

	int idx = start;
	i = start, j = mid + 1;
	for (; !(i >= mid + 1 && j >= end + 1); idx++)
	{
		if (temp1[i] >= temp2[j])
		{
			arr[idx] = temp1[i++];
		}
		else
		{
			arr[idx] = temp2[j++];
		}
	}
}
