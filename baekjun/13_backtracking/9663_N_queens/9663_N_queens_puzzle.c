#include <stdlib.h>
#include <stdio.h>

int		g_return;

void	check_uncheck(int N, int n_row, int n_col, int status, int *row, int *dia_des, int *dia_asc)
{
	row[n_row] = status;
	dia_des[n_col - n_row + N - 1] = status;
	dia_asc[n_row + n_col] = status;
}

void	find(int N, int n_col, int *row, int *dia_des, int *dia_asc)
{
	int n_row;

	if (n_col == N)
	{
		g_return++;
		return ;
	}
	n_row = 0;
	while (n_row < N)
	{
		if (!row[n_row] && !dia_des[n_col - n_row + N - 1] && !dia_asc[n_col + n_row])
		{
			check_uncheck(N, n_row, n_col, 1, row, dia_des, dia_asc);
			find(N, n_col + 1, row, dia_des, dia_asc);
			check_uncheck(N, n_row, n_col, 0, row, dia_des, dia_asc);
		}
		n_row++;
	}
}

void	init(int N, int *row, int *dia_des, int *dia_asc)
{
	int i;

	g_return = 0;
	i = 0;
	while (i < N)
		row[i++] = 0;
	i = 0;
	while (i < 2 * N - 1)
		dia_des[i++] = 0;
	i = 0;
	while (i < 2 * N - 1)
		dia_asc[i++] = 0;
}

int		N_queens_puzzle(int N)
{
	int *row = (int *)malloc(sizeof(int) * N);
	int *dia_des = (int *)malloc(sizeof(int) * (2 * N - 1));
	int *dia_asc = (int *)malloc(sizeof(int) * (2 * N - 1));


	init(N, row, dia_des, dia_asc);
	find(N, 0, row, dia_des, dia_asc);
	free(row);
	free(dia_des);
	free(dia_asc);
	return (g_return);
}

int main()
{
	int N;
	scanf("%d", &N);

	printf("%d\n", N_queens_puzzle(N));
}