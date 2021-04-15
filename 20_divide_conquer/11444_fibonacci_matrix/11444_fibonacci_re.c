#include <stdio.h>

typedef long long ll;
ll p = 1000000007;


ll memo[4];

void		recursive(ll n, ll iter)
{
	if (n <= iter)
		return ;
	if (iter == 0)
	{
		memo[0] = 0;
		memo[2] = 0;
	}
	else if (iter == 1)
	{
		memo[1] = 1;
		memo[2] = 1;
	}
	else
	{
		ll temp_memo[4];
		for (int i = 0; i < 2; i++)
			temp_memo[i] = memo[i + 1];
		temp_memo[2] = (temp_memo[0] % p + temp_memo[1] % p) % p;
		for (int i = 0; i < 3; i++)
			memo[i] = temp_memo[i];
	}
	recursive(n, iter + 1);
}



int main()
{
	ll n; scanf("%lld", &n);
	recursive(n , 0);
	printf("%lld\n", memo[2] % p);
	return 0;
}