#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort_ascending(int arr[], int N)
{
	int key, i, j, min;
	for (i = 0; i < N - 1; i++)
	{
		min = i;
		for (j = i + 1; j < N; j++)
			if (arr[j] < arr[min])
				min = j;
		if (i != min)
			swap(arr + i, arr + min);
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);

	sort_ascending(arr, N);

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);

	return (0);
}