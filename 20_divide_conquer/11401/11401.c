// 페르마의 소정리 :
#include <stdio.h>

typedef long long ll;
ll  p = 1000000007;

ll	calc(int a, int b, int c);
ll		fact(ll nb);


int main()
{
	int n, k; scanf("%d %d", &n, &k);
	ll num = fact(n);
	ll den = fact(n - k) * fact(k) % p;
	ll den2 = calc(den, p - 2, p);
	ll ret = num * den2 % p;
	printf("%lld\n", ret);
}


ll		fact(ll nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	nb *= fact(nb - 1);
	return (nb % p);
}


ll	calc(int a, int b, int c)
{
	ll temp;
	if (b == 0)
		return (1);
	else if (b % 2 == 0)
	{
		temp = calc(a, b / 2, c);
		temp = (temp * temp) % (ll)c;
		return temp;
	}
	else
	{
		temp = calc(a, b / 2, c);
		temp = temp * temp % c;
		temp = temp * a % c;
		return (temp);
	}
}