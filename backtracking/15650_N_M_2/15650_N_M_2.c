#include <stdio.h>

void print_board(int M, int board[])
{
	for (int i = 0; i < M - 1; i++)
		printf("%d ", board[i]);
	printf("%d\n", board[M - 1]);
}

void find(int N, int M, int board[], int location)
{
	if (location == M)
	{
		print_board(M, board);
		return ;
	}

	if (location == 0)
	{
		for (int fill = 1; fill <= N; fill++)
		{
			board[location] = fill;
			find(N, M, board, location + 1);
			board[location] = 0;}
	}
	else
	{
		for (int fill = board[location - 1] + 1; fill <= N; fill++)
		{
			board[location] = fill;
			find(N, M, board, location + 1);
			board[location] = 0;
		}
	}
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	int board[M];
	for (int i = 0; i < M; i++)
		board[i] = 0;

	find(N, M, board, 0);
}