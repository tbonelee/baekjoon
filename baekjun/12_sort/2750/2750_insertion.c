#include <stdio.h>

void sort_ascending(int arr[], int N)
{
	int key, i, j;
	for (i = 1; i < N; i++)
	{
		key = arr[i];
		for (j = 1; i - j >= 0 && arr[i - j] > key; j++)
			arr[i - j + 1] = arr[i - j];
		arr[i - j + 1] = key;
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