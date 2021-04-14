#include <stdio.h>

int A[101][101];
int B[101][101];
int C[101][101];

void solve(int n, int m, int k);

int main()
{
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}
	solve(n, m, k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
}
void solve(int n, int m, int k)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int temp = 0;
			for (int idx = 0; idx < m; idx++)
			{
				temp += A[i][idx] * B[idx][j];
			}
			C[i][j] = temp;
		}
	}
}