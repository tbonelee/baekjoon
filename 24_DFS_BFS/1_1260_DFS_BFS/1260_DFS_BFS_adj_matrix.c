#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int	g_DFS_check[1001];
int	g_BFS_check[1001];
int g_adj_matrix[1001][1001];
int g_Q[1001];
int g_head;
int g_tail;
int g_length;

void	DFS(int N, int V);
void	BFS(int N, int V);

int main()
{
	// 전역변수는 0으로 세팅되지만 혹시 몰라서..
	memset(g_adj_matrix, 0, sizeof(g_adj_matrix));
	memset(g_DFS_check, 0, sizeof(g_DFS_check));
	memset(g_BFS_check, 0, sizeof(g_BFS_check));

	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	int vert1, vert2;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &vert1, &vert2);
		g_adj_matrix[vert1][vert2] = 1;
		g_adj_matrix[vert2][vert1] = 1;
	}

	// printf("===g_adj_matrix===\n");
	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 1; j <= N; j++)
	// 	{
	// 		printf("%d ", g_adj_matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");



	DFS(N, V);
	printf("\n");
	BFS(N, V);

	return 0;
}

void	DFS(int N, int V)
{
	printf("%d ", V);
	g_DFS_check[V] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (g_adj_matrix[V][i] == 1 && g_DFS_check[i] == 0)
		{
			DFS(N, i);
		}
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
	g_head = 0; g_tail = 0; g_length = 1000;
	printf("%d ", V);
	g_BFS_check[V] = 1;
	enque(V);

	while (g_head != g_tail)
	{
		temp = deque();
		for (int i = 1; i <= N; i++)
		{
			if (g_adj_matrix[temp][i] == 1 && g_BFS_check[i] == 0)
			{
				printf("%d ", i);
				g_BFS_check[i] = 1;
				enque(i);
			}
		}
	}
}