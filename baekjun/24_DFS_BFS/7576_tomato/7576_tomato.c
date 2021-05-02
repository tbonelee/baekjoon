// BFS를 통해 거리 측정
// 소스 정점이 여러 개인 BFS로 생각할 수 있음
// 각 소스(익은 토마토)를 큐에 넣고
// BFS를 시행하면
// 거리가 1인 정점부터 차례대로 큐에 입력되면서 거리가 기록되고
// 그 다음에는 거리가 2, 거리가 3, 이런 식으로 큐에 입력 된다.

// 한 정점이 다른 정점에서 더 가까울 수 있는데 이미 거리가 기록되어서
// 그런 것을 놓치게 되는 건 아닌지 의문을 가질 수 있다.
// 하지만 그런 경우가 있다면 더 가까운 정점에서 먼저 방문되었을 것이므로 가까운 거리가 기록되었을 것이다.


// (초기에)
// map[][]값이 -2이면 -1을 입력받은 것이므로 토마토가 없는 곳
// map[][]값이 -1이면 0을 입력받은 곳이므로 익지 않은 토마토
// map[][]값이 0이면 1을 입력받은 곳이므로 익은 토마토

// BFS에서 익지 않은 토마토가 익은 토마토에서 도달 가능하면,
// map[][] 익은 토마토로부터의 거리를 기록함.

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_loc{
	int n;
	int m;
}	t_loc;

t_loc g_q[1000001];
int		g_leng = 1000000;
int		g_head = 1;
int		g_tail = 1;
int		n_vec[4] = {0, 0, -1, 1};
int		m_vec[4] = {-1, 1, 0, 0};

void	BFS(int N, int M, int map[][1001]);
void	enque(t_loc input);
t_loc	deque(void);

int main()
{
	int M, N; scanf("%d %d", &M, &N);
	int	map[1001][1001];
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
		{
			scanf("%d", &map[n][m]);
			map[n][m] -= 1;
		}
	t_loc temp;
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
		{
			if (map[n][m] == 0)
			{
				temp.n = n; temp.m = m;
				enque(temp);
			}
		}

	BFS(N, M, map);

	int max = INT_MIN;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			// printf("%2d", map[n][m]);
			if (map[n][m] == -1)
			{
				printf("-1\n");
				return 0;
			}
			if (map[n][m] > max)
				max = map[n][m];
		}
		// printf("\n");
	}
	printf("%d\n", max);
	return 0;
}

void	enque(t_loc input)
{
	g_q[g_tail] = input;
	if (g_tail == g_leng)
		g_tail = 1;
	else
		g_tail++;
	// printf("enque\n");
}

t_loc	deque(void)
{
	t_loc ret = g_q[g_head];
	if (g_head == g_leng)
		g_head = 1;
	else
		g_head++;
	// printf("deque\n");
	return (ret);
}

void	BFS(int N, int M, int map[][1001])
{
	// printf("bfs in, n = %d, m = %d\n", n, m);
	int n_, m_;
	t_loc temp;
	t_loc temp2;
	while (g_head != g_tail)
	{
		temp = deque();
		for (int i = 0; i < 4; i++)
		{
			n_ = temp.n + n_vec[i]; m_ = temp.m + m_vec[i];
			// printf("temp.n = %d, temp.m = %d, map[][] = %d\n", temp.n, temp.m, map[temp.m][temp.n]);
			if (n_ != -1 && m_ != -1 && n_ != N && m_ != M
			&& map[n_][m_] == -1)
			{
				if (map[n_][m_] == -1)
				{
					// printf("  (n_, m_) = (%d, %d), map[n_][m_] == -1 so change it to", n_, m_);
					map[n_][m_] = map[temp.n][temp.m] + 1;
					// printf("%d\n", map[n_][m_]);
					temp2.n = n_; temp2.m = m_;
					enque(temp2);
				}
			}
		}
	}

	// printf("BFS @ (n,m) = (%d, %d)\n", n, m);

}