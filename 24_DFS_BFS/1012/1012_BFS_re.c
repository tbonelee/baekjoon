#include <stdio.h>
#include <stdbool.h>
typedef struct s_location
{
	int m;
	int n;
}	t_location;
int 	m_vec[4] = {-1, 1, 0, 0};
int		n_vec[4] = {0, 0, -1, 1};
int		sub(bool map[][50], int M, int N, int m, int n);
int main()
{
	int T; scanf("%d", &T);
	bool map[50][50] = {false,};
	int M, N, K;
	int temp_m, temp_n;
	for (int i = 1; i <= T; i++)
	{
		scanf("%d %d %d", &M, &N, &K);
		for (int j = 1; j <= K; j++)
		{
			scanf("%d %d", &temp_m, &temp_n);
			map[temp_m][temp_n] = true;
		}
		int cnt = 0;
		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++)
				if (map[m][n] == true)
				{
					cnt++;
					sub(map, M, N, m, n);
				}
		printf("%d\n", cnt);
		for (int m = 0; m < M; m++)
			for (int n = 0; n < N; n++)
				map[m][n] = false;
	}
}

void	enque(t_location q[], int leng, int *tail, int m, int n)
{
	t_location input; input.m = m; input.n = n;
	q[*tail] = input;
	if (*tail == leng)
		*tail = 1;
	else
		*tail = *tail + 1;
}

t_location deque(t_location q[], int leng, int *head)
{
	t_location ret = q[*head];
	if (*head == leng)
		*head = 1;
	else
		*head = *head + 1;
	return (ret);
}

int		sub(bool map[][50], int M, int N, int m, int n)
{
	t_location q[2501], temp;
	int leng = 2500, head = 1, tail = 1;
	map[m][n] = false;
	enque(q, leng, &tail, m, n);
	while (head != tail)
	{
		int m_, n_;
		temp = deque(q, leng, &head);
		for (int i = 0; i < 4; i++)
		{
			m_ = temp.m + m_vec[i]; n_ = temp.n + n_vec[i];
			if (m_ != -1 && n_ != -1 && m_ != M && n_ != N
			&& map[m_][n_] == true)
			{
				map[m_][n_] = false;
				enque(q, leng, &tail, m_, n_);
			}
		}
	}
	return (0);
}
