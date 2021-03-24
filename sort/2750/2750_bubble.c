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
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j + 1 < N - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr + j, arr + j + 1);
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