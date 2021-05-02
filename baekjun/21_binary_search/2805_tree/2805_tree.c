#include <stdio.h>
#include <limits.h>

int N, M;
int tree[1000001];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &tree[i]);
	int start = 0; int end = 1000000005;

	int max	 = -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		long long ret = 0;
		for (int i = 0; i < N; i++)
		{
			ret += tree[i] > mid ? tree[i] - mid : 0;
		}
		if (ret >= M)
		{
			max = mid > max ? mid : max;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

	}
	printf("%d\n", max);
}