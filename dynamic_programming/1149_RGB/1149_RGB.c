#include <stdio.h>

#define MAX 2147483647

int MIN;
int sum = 0;


void find(int N, int arr[][3], int idx, int check[])
{
	if (idx == N)
	{
		if (sum < MIN)
			MIN = sum;
		return ;
	}

	for (int i = 0; i < 3; i++)
	{
		if (idx != 0 && check[idx - 1] != i)
		{
			check[idx] = i;
			sum += arr[idx][i];
			find(N, arr, idx + 1, check);
			sum -= arr[idx][i];
			check[idx] = -1;
		}
		else if (idx == 0)
		{
			check[idx] = i;
			sum += arr[idx][i];
			find(N, arr, idx + 1, check);
			sum -= arr[idx][i];
			check[idx] = -1;
		}
	}
}

void find_min(int N, int arr[][3], int sum[][3])
{
	if (N == 0)
		return ;

	
}






int main()
{
	MIN = MAX;

	int N;
	scanf("%d", &N);

	int arr[N + 1][3];
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	int sum[N + 1][3];
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			sum[i][j] = 0;

	find_min(N, arr, sum);

	int check[N];
	for (int i = 0; i < N; i++)
		check[i] = -1;

	// int memo[N + 1];
	// 만약 N == 5일 때 R/G/B를 선택하면서 누적된 sum을 기록할 때는
	// memo[0] = 0; memo[1] = 1; memo[2] = 2;를 기록한다. 나머지 칸에는 0이 되어 있고
	// 마지막 칸인 memo[N]에는 R/G/B선택으로 인한 비용 sum이 기록되도록 한다.
	// for (int i = 0; i < N + 1; i++)



	find(N, arr, 0, check);

	printf("%d\n", MIN);
	return 0;
}