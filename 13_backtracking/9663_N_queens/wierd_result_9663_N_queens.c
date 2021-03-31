#include <stdio.h>

int g_return;

void	check_uncheck(int N, int n_row, int n_col, int status, int row[], int dia_des[], int dia_asc[])
{
		for(int i = 0; i < 2 * N - 1; i++)
			printf("(1)before check dia_asc[%d] = %d (1) dia_des[%d] = %d\n", i, dia_asc[i], i, dia_des[i]);
			printf("\n");
	row[n_row] = status;
	for(int i = 0; i < 2 * N - 1; i++)
			printf("(2)before check dia_asc[%d] = %d (2) dia_des[%d] = %d\n", i, dia_asc[i], i, dia_des[i]);
		printf("\n");
	dia_des[n_col - n_row + (N - 1)] = status;
		for(int i = 0; i < 2 * N - 1; i++)
			printf("(3)before check dia_asc[%d] = %d (3) dia_des[%d] = %d\n", i, dia_asc[i], i , dia_des[i]);
	printf("\n");
	dia_asc[n_row + n_col] = status;

		for(int i = 0; i < 2 * N - 1; i++)
			printf("(3)before check dia_asc[%d] = %d (3) dia_des[%d] = %d\n", i, dia_asc[i], i , dia_des[i]);
	printf("\n");

	printf("(check)dia_asc[3] = %d\n", dia_asc[3]);
			printf("(check)status = %d, n_row = %d, n_col - n_row + (N - 1) = %d, n_row + n_col = %d\n", status, n_row, n_col - n_row + (N - 1) , n_row + n_col);
	printf("(check)row[%d] = %d, dia_des[%d] = %d, dia_asc[%d] = %d\n",  n_row, row[n_row],  n_col - n_row + N - 1,dia_des[n_col - n_row + (N - 1)],  n_col + n_row, dia_asc[n_col + n_row]);

}

void	find(int N, int row[], int dia_des[], int dia_asc[], int n_col)
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
		// if (n_col == 1)
		// {		printf("(sp) n_row = %d, n_col - n_row + (N - 1) = %d, n_row + n_col = %d\n",  n_row, n_col - n_row + (N - 1) , n_row + n_col);
		// 	printf("(sp)row[%d] = %d, dia_des[%d] = %d, dia_asc[%d] = %d\n",  n_row, row[n_row],  n_col - n_row + N - 1,dia_des[n_col - n_row + (N - 1)],  n_col + n_row, dia_asc[n_col + n_row]);
		// }
		printf("dia_asc[3] = %d\n", dia_asc[3]);
			printf("n_row = %d, n_col = %d\n", n_row, n_col);
			printf("row[%d] = %d, dia_des[%d] = %d, dia_asc[%d] = %d\n",  n_row, row[n_row],   n_col - n_row + N - 1, dia_des[n_col - n_row + (N - 1)] , n_row + n_col , dia_asc[n_col + n_row] );
		if (row[n_row] == 0 && dia_des[n_col - n_row + (N - 1)] == 0 && dia_asc[n_col + n_row] == 0)
		{
			// printf("(in)n_row = %d, n_col = %d\n", n_row, n_col);

			check_uncheck(N, n_row, n_col, 1, row, dia_des, dia_asc);
			printf("after check dia_asc[3] = %d\n", dia_asc[3]);
			find(N, row, dia_des, dia_asc, n_col + 1);
			check_uncheck(N, n_row, n_col, 0, row, dia_des, dia_asc);

			// printf("(out)n_row = %d, n_col = %d\n", n_row, n_col);
		}
		n_row++;
	}
}

void	init(int N, int row[], int dia_des[], int dia_asc[])
{
	int i;

	g_return = 0; //C89 이후 표준에 의해 전역변수는 0으로 초기화되므로 전역변수 유지시 삭제해도 무방
	i = 0;
	while (i < N)
		row[i++] = 0;
	i = 0;
	while (i < 2 * N - 1)
		dia_des[i++] = 0;
	i = 0;
	while (i < 2 * N - 1)
		dia_asc[i++] = 0;


	// for (int i = 0; i < 2 * N - 1; i++)
		// printf("dia_asc[i] = %d\n", dia_asc[i]);
}

int		ft_ten_queens_puzzle(int N, int row[], int dia_des[], int dia_asc[])
{
	init(N, row, dia_des, dia_asc);
	find(N, row, dia_des, dia_asc, 0);
	return (g_return);
}

int main()
{
	int		N;
	int		row[N];
	int		dia_des[2 * N - 1];
	int		dia_asc[2 * N - 1];
	scanf("%d", &N);

	printf("%d", ft_ten_queens_puzzle(N, row, dia_des, dia_asc));
}
