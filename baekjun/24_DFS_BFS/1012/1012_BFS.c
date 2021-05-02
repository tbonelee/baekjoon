// BFS를 통해 한 소스에서 탐색 시작.
// visited에서 방문되지 않은 곳 탐색해서 다시 탐색.
// 탐색 한 번 시작할 때마다 횟수 추가.

#include <stdio.h>
#include <stdbool.h>

typedef struct s_location
{
	int m;
	int n;
}	t_location;

void	find(bool map[][50], int M, int N);

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
		find(map, M, N);
	}
}

void	enque(t_location q[], int leng, int *tail, int m, int n)
{
	t_location input; input.m = m; input.n = n;
	q[*tail] = input;
	if (*tail == leng)
		*tail = 1;
	else
	{
		// printf("enque,");
		*tail = *tail + 1;
	}
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
	// printf("here (m, n) = (%d, %d)\n", m, n);
	map[m][n] = false;
	enque(q, leng, &tail, m, n);
	// printf("head = %d, tail = %d\n", head, tail);
	while (head != tail)
	{
		temp = deque(q, leng, &head);
		// printf("temp.m = %d, temp.n = %d\n", temp.m, temp.n);
		if (temp.m != 0 && map[temp.m - 1][temp.n])
		{
			map[temp.m - 1][temp.n] = false;
			enque(q, leng, &tail, temp.m - 1, temp.n);
		}
		if (temp.n != 0 && map[temp.m][temp.n - 1])
		{
			map[temp.m][temp.n - 1] = false;
			enque(q, leng, &tail, temp.m, temp.n - 1);
		}
		if (temp.m != M - 1 && map[temp.m + 1][temp.n])
		{
			// printf("123123123");
			map[temp.m + 1][temp.n] = false;
			enque(q, leng, &tail, temp.m + 1, temp.n);
		}
		if (temp.n != N - 1 && map[temp.m][temp.n + 1])
		{
			map[temp.m][temp.n + 1] = false;
			enque(q, leng, &tail, temp.m, temp.n + 1);
		}
	}
	return (0);
}

void	find(bool map[][50], int M, int N)
{
	int cnt = 0;
	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			if (map[m][n] == true)
			{
				cnt++;
				sub(map, M, N, m, n);
			}
		}
	}

	printf("%d\n", cnt);
}