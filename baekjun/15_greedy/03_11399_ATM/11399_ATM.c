// arr[i]를 오름차순으로 정렬한 후
// sum = ∑{ (N - i) * arr[i])  (from i = 0 to i = N - 1)

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	if (*((int *)a) > *((int *)b))
		return 1;
	else if (*((int *)a) == *((int *)b))
		return 0;
	else
		return -1;
}

int main()
{
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	qsort(arr, N, sizeof(int), &compare);

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += (N - i) * arr[i];

	printf("%d\n", sum);

	return 0;

}