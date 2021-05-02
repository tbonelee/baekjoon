// 시간복잡도 계산
// BFS 함수에 while 문 안의 if문의 논리연산에 동일하게 c의 시간이 걸린다고 하자.
// 한 칸에 대해 논리연산이 4c만큼 시간이 걸리는 것이다.
// 최악의 경우 모든 미로의 숫자가 1이고, 그렇게 되면 모든 칸을 다 훑게 될 것이고, N*M칸을 탐색하게 된다.
// 총 연산에서 논리 연산에 걸리는 시간은 4 * N * M * c이고 이는 O(N * M)으로 나타낼 수 있다.


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>




typedef struct s_adjlist t_adjlist;
typedef struct s_graph t_graph;

struct	s_adjlist
{
	t_adjlist	*prev;
	t_adjlist	*next;
	t_graph		*location;
};

// n이 커질수록 오른쪽에 위치
// m이 커질수록 아랫쪽에 위치
struct	s_graph
{
	int		n;
	int		m;
	char	is_path;
	bool	visited;
	int		dist;
};


int		g_q_length;
int		g_q_head;
int		g_q_tail;
t_graph	g_Q[10000];

void	BFS(int N, int M, t_graph map[][101]);
void	enque(t_graph input);
t_graph	deque();

int main()
{
	g_q_length = 10000;

	int N, M;
	scanf("%d %d", &N, &M);

	t_graph	map[101][101];


	// O(N * M)의 시간
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			// 앞에 한 칸 공백을 통해 버퍼에 개행문자 남아있을 때 스킵하도록 해줌
			scanf(" %c", &(map[i][j].is_path));
			map[i][j].n = i;
			map[i][j].m = j;
			map[i][j].visited = false;
			map[i][j].dist = INT_MAX;
		}
	}


	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 1; j <= M; j++)
	// 	{
	// 		printf("%c", map[i][j].is_path);
	// 	}
	// 	printf("\n");
	// }

	BFS(N, M, map);

	printf("%d\n", map[N][M].dist);

	// printf("===dist===\n");
	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 1; j <= M; j++)
	// 	{
	// 		printf("%11d", map[i][j].dist);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	// printf("===visited===\n");
	// for (int i = 1; i <= N; i++)
	// {
	// 	for (int j = 1; j <= M; j++)
	// 	{
	// 		printf(" %d", map[i][j].visited);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");


	printf("===is_path===\n");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			printf(" %c", map[i][j].is_path);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

void	BFS(int N, int M, t_graph map[][101])
{
	int i = 1, j = 1;
	map[i][j].visited = true;
	map[i][j].dist = 1;
	enque(map[i][j]);

	while (g_q_head != g_q_tail)
	{
		// enque와 deque는 각각 Θ(1)의 시간
		t_graph temp = deque();
		i = temp.n; j = temp.m;
		if (i - 1 != 0 && map[i - 1][j].visited == false && map[i - 1][j].is_path == '1')
		{
			map[i - 1][j].visited = true;
			map[i - 1][j].dist = map[i][j].dist + 1;
			enque(map[i - 1][j]);
		}
		if (j - 1 != 0 && map[i][j - 1].visited == false && map[i][j - 1].is_path == '1')
		{
			map[i][j - 1].visited = true;
			map[i][j - 1].dist = map[i][j].dist + 1;
			enque(map[i][j - 1]);
		}
		if (i + 1 <= N && map[i + 1][j].visited == false && map[i + 1][j].is_path == '1')
		{
			map[i + 1][j].visited = true;
			map[i + 1][j].dist = map[i][j].dist + 1;
			enque(map[i + 1][j]);
		}
		if (j + 1 <= M && map[i][j + 1].visited == false && map[i][j + 1].is_path == '1')
		{
			map[i][j + 1].visited = true;
			map[i][j + 1].dist = map[i][j].dist + 1;
			enque(map[i][j + 1]);
		}
	}
}

void	enque(t_graph input)
{
	g_Q[g_q_tail] = input;
	if (g_q_tail + 1 == g_q_length)
		g_q_tail = 0;
	else
		g_q_tail++;
}

t_graph	deque(void)
{
	t_graph ret = g_Q[g_q_head];
	if (g_q_head + 1 == g_q_length)
		g_q_head = 0;
	else
		g_q_head++;
	return (ret);
}