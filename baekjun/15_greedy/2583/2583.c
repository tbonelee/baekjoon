// BFS의 지렁이 문제를 활용

// map에서 도형이 위치한 영역은 -1로 칠하고
// 나머지 영역에서는 (j, k) = (0,0)부터 map(j,k)가 0인 요소부터 한 칸씩 BFS 실행
// BFS를 한 번 실행할 때마다 cnt는 하나씩 증가(cnt는 나눠진 영역의 갯수)
// BFS를 하면서 map = 0인 요소를 방문할 때마다 area[cnt]가 하나씩 증가(area[cnt]는 한 영역의 넓이)

// 전체에 대해 가능한 BFS를 모두 시행한 후 영역의 넓이인 area를 qsort로 정렬

// 그 후 출력

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_block{
	int n_left, m_left;
	int n_right, m_right;
} t_block;

typedef struct s_pos{
	int n,m;
} t_pos;

int M, N, K;

t_pos Q[101];
int head = 0;
int mvec[4] = {0, 0, -1, 1};
int nvec[4] = {-1, 1, 0, 0};

int comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	scanf("%d %d %d", &M, &N, &K);
	t_block *arr = (t_block *)calloc(K, sizeof(t_block));
	for (int i = 0; i < K; i++)
		scanf("%d %d %d %d", &arr[i].n_left, &arr[i].m_left, &arr[i].n_right, &arr[i].m_right);
	int map[M][N];
	memset(map, 0, sizeof(map));
	for (int i = 0; i < K; i++)
	{
		for (int j = arr[i].m_left; j < arr[i].m_right; j++)
			for (int k = arr[i].n_left; k < arr[i].n_right; k++)
			{
				map[j][k] = -1;
			}
	}
	int cnt = 0;
	int area[10001];
	memset(area, 0, sizeof(area));
	for (int j = 0; j < M; j++)
		for (int k = 0; k < N; k++)
		{
			if (map[j][k] == 0)
			{
				cnt++;
				map[j][k] = 1; area[cnt]++;
				int jj = j, kk = k;
				t_pos temp;
				temp.m = jj; temp.n = kk;
				t_pos Q[10001];
				int head = 1, tail = 1;
				Q[tail++] = temp;
				while (head != tail)
				{
					temp = Q[head];
					head = head == 10000 ? 1 : head + 1;
					for (int i = 0; i < 4; i++)
					{
						jj = temp.m + mvec[i];
						kk = temp.n + nvec[i];
						if (jj < 0 || kk < 0 || jj >= M || kk >= N)
							continue;
						else
						{
							if (map[jj][kk] == 0)
							{
								map[jj][kk] = 1; area[cnt]++;
								t_pos temp2;
								temp2.m = jj; temp2.n = kk;
								Q[tail] = temp2;
								tail = tail == 10000 ? 1 : tail + 1;
							}
						}
					}

				}
			}
		}
	printf("%d\n", cnt);
	qsort(area + 1, cnt, sizeof(int), &comp);
	for (int i = 1; i <= cnt; i++)
		printf("%d ", area[i]);
	printf("\n");
	free(arr);
	return 0;
}