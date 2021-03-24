#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int heap[], int num)
{
	for (int i = num; i >= 2; i--)
		if (heap[i] > heap[i / 2])
			swap(heap + i, heap + (i / 2));
}

void heap_delete(int heap[], int num)
{
	int i = 1;

	while (i * 2 <= num)
	{
		if (i * 2 + 1 > num) // && heap[i] < heap[2 * i])
		{
			if (heap[i] < heap[2 * i])
				swap(heap + i, heap + (2 * i));
			break;
		}
		else if (heap[i] < heap[2 * i] && heap[2 * i] >= heap[2 * i + 1])
		{
			swap(heap + i, heap + (2 * i));
			i = 2 * i;

		}
		else if (heap[i] < heap[2 * i + 1] && heap[2 * i] <= heap[2 * i + 1])
		{
			swap(heap + i, heap + (2 * i + 1));
			i = 2 * i + 1;
		}
		else
			break;
	}
}

void heap_sort(int heap[], int num)
{
	heapify(heap, num);

	for (int i = 1; i < num; i++)
	{
		swap(&heap[1], &heap[(num + 1) - i]);
 // 두 개만 남았을 때는 위에서 스왑해주면서 오름차순으로 정렬이 되므로
 // 굳이 heapify하지 않도록 아래에 if조건을 넣어줌
 // 하지만 그냥 그 때도 heapify해도 무방(if 조건 빼줘도 무방하다는 의미, 어차피 바꿀 것 없으므로 아무 것도 스왑하지 않음)
		if (i != num - 1)
			heap_delete(heap, num - i);
	}

}

int main()
{
	int N;
	scanf("%d", &N);

	int heap[N + 1]; // index 표기 편의상 0번째 요소는 사용하지 않기로
	for (int i = 1; i <= N; i++)
		scanf("%d", heap + i);

	heap_sort(heap, N);

	for (int i = 1; i <= N; i++)
		printf("%d\n", heap[i]);

	return (0);
}