#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool	g_graph[101][101];
bool	g_DFS_check[101];
int		g_count;

void	DFS(int N, int V)
{
	g_count++;
	g_DFS_check[V] = true;

	for (int i = 1; i <= N; i++)
	{
		if (g_DFS_check[i] == false && g_graph[V][i] == true)
		{
			DFS(N, i);
		}
	}
}

int main()
{
	// 전역변수지만 혹시 몰라서..
	memset(g_graph, 0, sizeof(g_graph));
	memset(g_DFS_check, 0, sizeof(g_DFS_check));
	g_count = 0;

	int N, M;
	scanf("%d %d", &N, &M);

	int num1, num2;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &num1, &num2);
		g_graph[num1][num2] = true;
		g_graph[num2][num1] = true;
	}

	DFS(N, 1);
	printf("%d\n", g_count - 1);

	return 0;
}