// 만든 랜선 갯수가 딱 맞는 경우에만 결과로 쳐줬는데, 더 많은 경우에도 결과로 해주는 거로 바꾼 뒤에야 통과
// 원하는 갯수 N이 있을 때, N -1과 N + 1개로 자를 수는 있는데 N개로는 자를 수 없는 경우를 고려하지 못한 것 같다

#include <stdio.h>

typedef long long ll;

ll K, N;
ll arr[10001];
ll result;
ll kmax = 0;
ll maxret = 0;

void	find(void);

int main()
{
	scanf("%lld %lld", &K, &N);
	for (ll i = 1; i <= K; i++)
		scanf("%lld", &arr[i]);
	for (ll i = 1; i <= K; i++)
	{
		if (arr[i] > kmax)
			kmax = arr[i];
	}
	// prllf("kmax = %d\n", kmax);
	find();
	printf("%lld\n", maxret);
}

void	find(void)
{
	ll start = 1;
	ll end = kmax;
	ll mid;
	while (start <= end)
	{
		mid = (start + end) / 2;

		ll ret = 0;
		for (ll i = 1; i <= K; i++)
		{
			ret += arr[i] / mid;
		}
		if (ret >= N && maxret < mid)
			maxret = mid;

		if (ret >= N) // key <= target
			start = mid + 1;
		else if (ret < N) // key > target
		{
			end = mid;
			if (start == end)
				return ;
		}
	}
	// result = start;
	// if (start + 1 == end)
	// {
	// 	ll ret = 0;
	// 	for (ll i = 1; i <=K; i++)
	// 	{
	// 		ret += arr[i] / end;
	// 	}
	// 	if (ret == N)
	// 		result = end;
	// }
}