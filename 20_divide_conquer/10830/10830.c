#include <stdio.h>

int A[5][5];
int Aout[5][5];
int Atemp[5][5];

void sqr(int n, int m, int k);
void multiply(int n, int m, int k);
void	rec(int n, int b);

int main()
{
	int n, b;
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
			Aout[i][j] = A[i][j];

		}
	}
	rec(n, b);
	// solve(n, m, k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", Aout[i][j]);
		}
		printf("\n");
	}
}

void	rec(int n, int b)
{
	if (b == 1)
		return ;
	else if (b % 2 == 0)
	{
		rec(n, b / 2);
		sqr(n, n, n);
	}
	else if (b % 2 == 1)
	{
		rec(n, b / 2);
		sqr(n, n, n);
		multiply (n, n, n);
	}


}
void sqr(int n, int m, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			long long temp = 0;
			for (int idx = 0; idx < m; idx++)
			{
				temp += Aout[i][idx] * Aout[idx][j];
			}
			Atemp[i][j] = temp % 1000;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			Aout[i][j] = Atemp[i][j];
		}
	}
}
void multiply(int n, int m, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			long long temp = 0;
			for (int idx = 0; idx < m; idx++)
			{
				temp += Aout[i][idx] * A[idx][j];
			}
			Atemp[i][j] = temp % 1000;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			Aout[i][j] = Atemp[i][j];
		}
	}
}