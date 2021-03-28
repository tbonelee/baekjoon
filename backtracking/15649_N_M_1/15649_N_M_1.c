#include <stdio.h>

void print_board(int M, int board[])
{
	for (int i = 0; i < M - 1; i++)
		printf("%d ", board[i]);
	printf("%d\n", board[M - 1]);
}

void find(int N, int M, int forcheck[], int board[], int location)
{
	if (location == M)
	{
		print_board(M, board);
		return ;
	}

	for (int fill = 1; fill <= N; fill++)
		if (forcheck[fill - 1] == 0) // 이미 놓인 수인지 확인(-1하는 것은 인덱스가 0부터 시작하는 것 때문에 보정)
		{
			forcheck[fill - 1] = 1;
			board[location] = fill;
			find(N, M, forcheck, board, location + 1);
			board[location] = 0;
			forcheck[fill - 1] = 0;
		}
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	int forcheck[N];
	for (int i = 0; i < N; i++)
		forcheck[i] = 0;

	int board[M];
	for (int i = 0; i < M; i++)
		board[i] = 0;

	find(N, M, forcheck, board, 0);
}