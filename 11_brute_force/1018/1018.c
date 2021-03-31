#include <stdio.h>

int g_min = 64;

int main()
{
	int row;
	int col;
	scanf("%d %d", &row, &col);

	char board[row][col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			scanf(" %c", &board[i][j]);

	int min1;
	int min2;
	int temp;

	for (int i = 0; i < row - 7; i++)
		for (int j = 0; j < col- 7; j++)
		{
			min1 = 0;
			min2 = 0;
			for (int ii = i, i_idx = 0; i_idx < 8; i_idx++)
				for (int jj = j, j_idx = 0; j_idx < 8; j_idx++)
				{
					if (((ii + i_idx) + (jj + j_idx)) % 2 == 0)
					{
						if (board[ii + i_idx][jj + j_idx] == 'B')
							min1++;
						else if (board[ii + i_idx][jj + j_idx] == 'W')
							min2++;
					}
					else if (((ii + i_idx) + (jj + j_idx)) % 2 == 1)
					{
						if (board[ii + i_idx][jj + j_idx] == 'W')
							min1++;
						else if (board[ii + i_idx][jj + j_idx] == 'B')
							min2++;
					}
				}
			if (g_min > (temp = (min1 > min2 ? min2 : min1)))
				g_min = temp;
		}
	printf("%d", g_min);
	return 0;


}