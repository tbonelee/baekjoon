// 행렬의 i번째 행에서 어떤 값 x보다 작은 원소의 갯수를 찾아보자

// i번째 행에서 x 이하인 수 y를 찾으면 y는 (y / i)번째에 있음을 알 수 있다.
// 따라서 i행에서 x 이하인 수의 갯수는 x / i와 n 중 작은 수가 된다.

// 행렬의 원소중 가장 작은 값은 1, 가장 큰 값은 n*n이다.
// 이를 이용해서 이분 탐색을 시행한다.
// start = 1, end = n*n; mid = (start + end) / 2;
// mid라는 값이 B에서 몇 번째 위치(올 수 있는 위치 중 가장 마지막 위치)에 있는지 구해보자.
// 이는 for문에서 각 행 별로 min(x / i, n)의 값을 더해줘서 구할 수 있다.

// 이렇게 구한 원소값 x의 최대 인덱스가 목표 인덱스 k보다 크고 기존에 구한 (x의)최대 인덱스보다 작으면 일단 기록을 갱신한다.
// 그 후 end = mid - 1;을 통해 그 앞에 더 k에 가까운 최대 인덱스를 갖는 x가 있는지 탐색하게 된다.

// 여기서 구하는 것은 최대인덱스이므로 k와 절대 같게 나오지 않을 수 있다.
// 만약 목표하는 원소값이지만 최대인덱스가 k보다 커서 그보다 앞에 있는 원소들에서 다시 이분 탐색을 하는 경우를 생각해보자.
// 그러면 그 앞에 있는 원소값의 최대 인덱스는 k보다 작기 때문에 기록이 갱신되지 않는다.



#include <stdio.h>
#include <limits.h>
typedef long long ll;

ll n,k;

extern inline ll min(ll a, ll b)
{
	return (a < b ? a : b);
}

int main()
{
	scanf("%lld\n%lld", &n, &k);

	ll start = 1, end = n * n;
	ll memo = LLONG_MAX;
	while (start <= end)
	{
		ll mid = (start + end) / 2;
		ll cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(mid / i, n);
		}
		if (cnt >= k)
		{
			if (mid < memo)
				memo = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	printf("%lld\n", memo);

	return 0;

}