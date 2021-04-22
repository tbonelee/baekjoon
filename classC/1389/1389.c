#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int n, m;
int g_Q[5001];
int g_tail = 1;
int g_head = 1;
int g_length = 5000;
int g_BFS_check[5001];
int g_dist[5001];
int g_adj_matrix[5001][5001];

void	BFS(int N, int V);
int main()
{
	scanf("%d %d", &n, &m);
	memset(g_adj_matrix, 0, sizeof(g_adj_matrix));
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		g_adj_matrix[a][b] = 1;
		g_adj_matrix[b][a] = 1;
	}
	int min = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		memset(g_BFS_check, 0, sizeof(g_BFS_check));
		memset(g_dist, 0, sizeof(g_dist));
		BFS(n, i);
		int sum = 0;
		for (int j = 1; j <= n; j++)
			sum += g_dist[j];
		if (sum < min)
			min = sum;
	}
}

void	enque(int num)
{
	g_Q[g_tail] = num;
	if (g_tail == g_length)
		g_tail = 1;
	else
		g_tail++;
}

int		deque(void)
{
	int ret = g_Q[g_head];
	if (g_head == g_length)
		g_head = 1;
	else
		g_head++;
	return (ret);
}

void	BFS(int N, int V)
{
	int temp;
	g_BFS_check[V] = 1;
	g_dist[V] = 0;
	enque(V);

	while (g_head != g_tail)
	{
		temp = deque();
		int dist = g_dist[temp];
		for (int i = 1; i <= N; i++)
		{
			if (g_adj_matrix[temp][i] == 1 && g_BFS_check[i] == 0)
			{
				g_BFS_check[i] = 1;
				g_dist[i] = dist + 1;
				enque(i);
			}
		}
	}
}