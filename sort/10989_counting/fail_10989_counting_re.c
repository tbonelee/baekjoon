#include <stdio.h>
#include <stdlib.h>

void find_min_max(int arr[], int N, int *min, int *max)
{
	*min = arr[0];
	*max = arr[0];

	for (int i = 0; i < N; i++)
	{
		if (arr[i] < *min)
			*min = arr[i];
		else if (arr[i] > *max)
			*max = arr[i];
	}
}

void init_fill_counting(int arr[], int counting[], int N, int min, int max)
{
	for (int i = 0; i < max - min + 1; i++)
		counting[i] = 0;
	for (int i = 0; i < N; i++)
		counting[arr[i] - min]++;
	for (int i = 1; i < max - min + 1; i++)
		counting[i] += counting[i - 1];
}

void fill_dest(int arr[], int dest[], int counting[], int N, int min)
{
	for (int i = N - 1; i >= 0; i--)
	{
		dest[counting[arr[i] - min] - 1] = arr[i];
		counting[arr[i] - min]--;
	}
}

void counting_sort_first(int *arr, int N, int min, int max)
{


	int *ret = (int *)malloc(sizeof(int) * (max - min + 1));
	return (ret);


}

void counting_sort_second(int *arr, int *counting, int N, int min, int max)
{
	init_fill_counting(arr, counting, N, min, max);

	int *dest = (int *)malloc(sizeof(int) * N);
	fill_dest(arr, dest, counting, N, min);
}

int main()
{
	int N;

	scanf("%d", &N);

	int *arr = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int min, max;
	find_min_max(arr, N, &min, &max);

	int *counting = counting_sort_first(arr, N, min, max);
	int *dest = counting_sort_second(arr, counting, N, min, max);

	for (int i = 0; i < N; i++)
		printf("%d\n", dest[i]);

	return 0;
}