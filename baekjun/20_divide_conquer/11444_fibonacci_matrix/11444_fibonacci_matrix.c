#include <stdio.h>

typedef long long ll;
ll p = 1000000007;

// ll		sqr(ll nb)
// {
// 	ll temp = nb % p;
// 	return (temp * temp % p);
// }

// ll		ft_fibonacci(ll index)
// {
// 	ll t;

// 	t = index / 2;
// 	if (index < 0)
// 		return (-1);
// 	else if (index == 0)
// 		return (0);
// 	else if (index == 1)
// 		return (1);
// 	else if (index == 2)
// 		return (1);
// 	else if (index > 2 && index % 2 == 1)
// 		return ((sqr(ft_fibonacci(t + 1)) % p + sqr(ft_fibonacci(t))% p ) % p);
// 	return ((ft_fibonacci(t) * (( (2 * ft_fibonacci(t + 1)) % p  - ft_fibonacci(t)) % p) ) % p);
// }



#include <stdio.h>

ll A[10][10];
ll Aout[10][10];
ll Atemp[10][10];

void sqr(ll n);
void multiply(ll n);
void	rec(ll n, ll b);




int main()
{
	ll n; scanf("%lld", &n);

	A[0][0] = 1; Aout[0][0] = 1;
	A[0][1] = 1; Aout[0][1] = 1;
	A[1][0] = 1; Aout[1][0] = 1;
	A[1][1] = 0; Aout[1][1] = 0;

	if (n == 0)
		printf("0\n");
	else
	{
		rec(2, n);
		printf("%lld\n", Aout[0][1] % p);
	}
	return 0;
}

void	rec(ll n, ll b)
{
	if (b == 1)
		return ;
	else if (b % 2 == 0)
	{
		rec(n, b / 2);
		sqr(n);
	}
	else if (b % 2 == 1)
	{
		rec(n, b / 2);
		sqr(n);
		multiply (n);
	}


}
void sqr(ll n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long temp = 0;
			for (int idx = 0; idx < n; idx++)
			{
				temp = (temp + (Aout[i][idx] % p) * (Aout[idx][j] % p)) % p;
			}
			Atemp[i][j] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Aout[i][j] = Atemp[i][j];
		}
	}
}
void multiply(ll n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long temp = 0;
			for (int idx = 0; idx < n; idx++)
			{
				temp = (temp + (Aout[i][idx] % p) * (A[idx][j] % p)) % p;
			}
			Atemp[i][j] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Aout[i][j] = Atemp[i][j];
		}
	}
}
