#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort(int arr[], int start, int end)
{
	int key = start;
	int i = start + 1, j = end;

	if (start - 1 == end)
		return ;
	for (;;)
	{
		for (; i <= end; i++)
			if (arr[i] > arr[key]) // || i == end)
				break;
		for (; j >= start + 1; j--)
			if (arr[j] < arr[key]) // || j == )
				break;
		// cf) i가 증가, arr[i]가 이전에 만났던 요소 값이라는 것은
		// 그 전에 j도 그 자리를 지나쳤다는 것
		// 따라서 똑같은 값이 한 번 스왑하고 다시 스왑될 일은 없음.(j도 마찬가지)
		if (j < i)
			break;
		swap(arr + i, arr + j);
	}
	swap(arr + key, arr + j);
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}


int main()
{
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);

	quick_sort(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
	return 0;
}