#include <stdio.h>
#include <stdlib.h>

int		box_where(int i, int j)
{
	return ((i / 3) * 3 + (j / 3));
}

void print_board(int board[][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (j < 8)
				printf("%d ", board[i][j]);
			else
				printf("%d\n", board[i][j]);
		}
}

void check_uncheck(int status, int i, int j, int fill, int check_row[][9], int check_col[][9], int check_box[][9])
{
	check_box[box_where(i, j)][fill - 1] = status;
	check_row[i][fill - 1] = status;
	check_col[j][fill - 1] = status;
}

void find(int board[][9], int check_row[][9], int check_col[][9], int check_box[][9], int i, int j)
{
	if (i == 9)
	{
		print_board(board);
		exit(0);
	}

	if (board[i][j] == 0)
	{
		for (int fill = 1; fill <= 9; fill++)
		{
			if (check_row[i][fill - 1] == 0 && check_col[j][fill - 1] == 0
			&& check_box[box_where(i, j)][fill - 1] == 0)
			{
				board[i][j] = fill;
				check_uncheck(1, i, j, fill, check_row, check_col, check_box);
				if (j < 8)
					find(board, check_row, check_col, check_box, i, j + 1);
				else
					find(board, check_row, check_col, check_box, i + 1, 0);
				check_uncheck(0, i, j, fill, check_row, check_col, check_box);
				board[i][j] = 0;
			}
		}
	}
	else
	{
		if (j < 8)
			find(board, check_row, check_col, check_box, i, j + 1);
		else
			find(board, check_row, check_col, check_box, i + 1, 0);
	}
}

int main()
{
	int board[9][9];

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &board[i][j]);

	int check_row[9][9]; // check_row[i][j]는 i인덱스 행에서 j+1번째에 해당하는 숫자가 이미 등장한 경우 1 이상
	int check_col[9][9]; // check_col[i][j]는 i인덱스 열에서 j+1번째에 해당하는 숫자가 이미 등장한 경우 1 이상
	int check_box[9][9]; // check_row[i][j]는 i인덱스 박스(왼쪽 위부터 차례대로 순번)에서 j+1번째에 해당하는 숫자가 이미 등장한 경우 1 이상

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			check_row[i][j] = 0;
			check_col[i][j] = 0;
			check_box[i][j] = 0;
		}

	int element;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != 0)
			{
				element = board[i][j];

				check_row[i][element - 1] = 1;
				check_col[j][element - 1] = 1;
				check_box[box_where(i, j)][element - 1] = 1;
			}
		}

	find(board, check_row, check_col, check_box, 0, 0);
}