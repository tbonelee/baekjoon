
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_loc{
	int n;
	int m;
	int h;
}	t_loc;

t_loc g_q[1000001];
int		g_leng = 1000000;
int		g_head = 1;
int		g_tail = 1;
int		n_vec[6] = {0, 0, -1, 1, 0, 0};
int		m_vec[6] = {-1, 1, 0, 0, 0, 0};
int		h_vec[6] = {0, 0, 0, 0, -1, 1};

void	BFS(int N, int M, int H, int map[][101][101]);
void	enque(t_loc input);
t_loc	deque(void);

int main()
{
	int M, N, H; scanf("%d %d %d", &M, &N, &H);
	int	map[101][101][101];
	for (int h = 0; h < H; h++)
		for (int n = 0; n < N; n++)
			for (int m = 0; m < M; m++)
			{

				scanf("%d", &map[n][m][h]);
				map[n][m][h] -= 1;
			}
	t_loc temp;
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			for (int h = 0; h < H; h++)
			{
				if (map[n][m][h] == 0)
				{
					temp.n = n; temp.m = m; temp.h = h;
					enque(temp);
				}
			}

	BFS(N, M, H, map);

	int max = INT_MIN;
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			for (int h = 0; h < H; h++)
			{
				// printf("%2d", map[n][m]);
				if (map[n][m][h] == -1)
				{
					printf("-1\n");
					return 0;
				}
				if (map[n][m][h] > max)
					max = map[n][m][h];
			}
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

void	BFS(int N, int M, int H, int map[][101][101])
{
	// printf("bfs in, n = %d, m = %d\n", n, m);
	int n_, m_, h_;
	t_loc temp;
	t_loc temp2;
	while (g_head != g_tail)
	{
		temp = deque();
		for (int i = 0; i < 6; i++)
		{
			n_ = temp.n + n_vec[i]; m_ = temp.m + m_vec[i]; h_ = temp.h + h_vec[i];
			// printf("temp.n = %d, temp.m = %d, map[][] = %d\n", temp.n, temp.m, map[temp.m][temp.n]);
			if (n_ != -1 && m_ != -1 && h_ != -1 && n_ != N && m_ != M && h_ != H
			&& map[n_][m_][h_] == -1)
			{
				if (map[n_][m_][h_] == -1)
				{
					// printf("  (n_, m_) = (%d, %d), map[n_][m_] == -1 so change it to", n_, m_);
					map[n_][m_][h_] = map[temp.n][temp.m][temp.h] + 1;
					// printf("%d\n", map[n_][m_]);
					temp2.n = n_; temp2.m = m_; temp2.h = h_;
					enque(temp2);
				}
			}
		}
	}

	// printf("BFS @ (n,m) = (%d, %d)\n", n, m);

}