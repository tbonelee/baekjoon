#include <stdio.h>

void	printornot(int cnt_again, int row, int col, int flag)
{
	if (cnt_again == 1)
	{
		if (flag == 1)
			printf("*");
		else
			printf(" ");
		return ;
	}
	if (row % 3 == 2 && col % 3 == 2)
		flag = 0;
	printornot(cnt_again / 3, (row - 1) / 3 + 1, (col - 1) / 3 + 1, flag);
}

void	printstar_col(int cnt, int cnt_again, int col, int row)
{
	if (cnt == 1)
	{
		printornot(cnt_again, row, col, 1);
		if (cnt_again == col)
			printf("\n");
	}
	else
	{
		printstar_col(cnt / 3, cnt_again * 3, col * 3 - 2, row);
		printstar_col(cnt / 3, cnt_again * 3, col * 3 - 1, row);
		printstar_col(cnt / 3, cnt_again * 3, col * 3 - 0, row);
	}
}


// num * cnt는 항상 처음에 입력 받은 n 값과 같게 된다.
void	printstar_row(int num, int cnt, int row)
{
	if (num == 1)
	{
		printstar_col(cnt / 3, 3, 1, row);
		printstar_col(cnt / 3, 3, 2, row);
		printstar_col(cnt / 3, 3, 3, row);
	}
	else
	{

		printstar_row(num / 3, cnt * 3, row * 3 - 2);
		printstar_row(num / 3, cnt * 3, row * 3 - 1);
		printstar_row(num / 3, cnt * 3, row * 3 - 0);
	}
}

int		printstar(int n)
{
	printstar_row(n/3, 3, 1);
	printstar_row(n/3, 3, 2);
	printstar_row(n/3, 3, 3);
}

int main()
{
	int n;
	scanf("%d", &n);
	printstar(n);
	// printstar(27);
	return 0;
}
