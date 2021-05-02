// memo에는 i번째 날의 상담을 한다고 했을 때, 첫날부터 i번째 날까지의 최대 수익을 기록

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N; scanf("%d", &N);
	int *arr_t = (int *)calloc(N + 1, sizeof(int));
	int *arr_p = (int *)calloc(N + 1, sizeof(int));
	int *memo = (int *)calloc(N + 1, sizeof(int));
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &arr_t[i], &arr_p[i]);

	for (int i = 1; i <= N; i++)
	{
		int max = 0;
		// i - 50까지 가야, 만약 i직전 50개 중에 쓸 수 있는 값이 없으면(전부 상담이 i번째랑 겹쳐서) i - 50번째 값이라도 쓸 수 있음
		for (int j = i - 1; j >= i - 100 && j >= 1; j--)
		{
			if (j + arr_t[j] - 1 < i)
				max = memo[j] > max ? memo[j] : max;
		}
		memo[i] = max + arr_p[i];
	}
	int i = N + 1;
	int max = 0;
	for (int j = 1; j <= N; j++)
		if (j + arr_t[j] - 1 < i)
			max = memo[j] > max ? memo[j] : max;
	printf("%d\n", max);




	free(arr_t);
	free(arr_p);
}