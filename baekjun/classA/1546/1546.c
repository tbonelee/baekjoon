#include <stdio.h>

int N;

int main()
{
	scanf("%d", &N);
	int arr[1001];
	for (int i = 1; i <= N; i++)
		scanf("%d", arr + i);
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	long double arr2[1001];
	for (int i = 1; i <= N; i++)
	{
		arr2[i] = (long double)arr[i] / max;
		arr2[i] *= 100;
	}
	long double sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += arr2[i];
	}
	printf("%.2Lf\n", sum / N);
}