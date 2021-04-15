// 처음에 테스트 다 통과한 줄 알았으나
// 2 1
// 1000 1000
// 1000 1000
// 처럼 들어오면 rec으로 들어가지 않아서 1000에 대한 모듈로 연산이 일어나지 않고
// 0 0
// 0 0이 출력되지 않고
// 1000 1000
// 1000 1000이 출력됨

// 나머지를 출력하라는 문제는 출력하는 순간에도 한 번 더 나머지 연산을 해주는 것이 안전하겠다


#include <stdio.h>

int A[10][10];
int Aout[10][10];
int Atemp[10][10];

void sqr(int n, int m, int k);
void multiply(int n, int m, int k);
void	rec(int n, long long b);

int main()
{
	int n;
	long long b;
	scanf("%d %lld", &n, &b);
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
			printf("%d ", Aout[i][j] % 1000);
		}
		printf("\n");
	}
}

void	rec(int n, long long b)
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