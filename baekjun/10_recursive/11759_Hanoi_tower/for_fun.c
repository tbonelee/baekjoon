#include <stdio.h>

void	hanoi(int n, int from, int to, int other)
{


	// /// 기존
	// if (n == 0)
	// 	return ;
	// hanoi(n - 1, from, other, to);
	// printf("%d %d\n", from, to);
	// hanoi(n - 1, other, to, from);

	// /// n - 2가 들어가게
	// if (n == 1)
	// 	printf("%d %d\n", from, to);
	// else if (n == 0)
	// 	return ;
	// else
	// {
	// 	hanoi(n - 2, from, to, other);
	// 	printf("%d %d\n", from, other);
	// 	hanoi(n - 2, to, other, from);
	// 	printf("%d %d\n", from, to);
	// 	hanoi(n - 1, other, to, from);
	// }

	// /// n - 2가 들어가게(ver.2)
	// if (n == 0)
	// 	return ;
	// else if (n == 1)
	// 	printf("%d %d\n", from, to);
	// else if (n == 2)
	// {
	// 	hanoi(1, from, other, to);
	// 	hanoi(1, from, to, other);
	// 	hanoi(1, other, to, from);
	// }
	// else
	// {
	// 	hanoi(n - 2, from, to, other);
	// 	hanoi(1, from, other, to);
	// 	hanoi(n - 2, to, from, other);
	// 	hanoi(1, from, to, other);
	// 	hanoi(n - 2, other, from, to);
	// 	hanoi(1, other, to, from);
	// 	hanoi(n - 2, other, to, from);
	// }

	/// n - 3이 들어가게
	if (n == 0)
		return ;
	else if (n == 1)
		printf("%d %d\n", from, to);
	else if (n == 2)
	{
		hanoi(1, from, other, to);
		hanoi(1, from, to, other);
		hanoi(1, other, to, from);
	}
	else if (n == 3)
	{
		hanoi(n - 2, from, to, other);
		hanoi(1, from, other, to);
		hanoi(n - 2, to, from, other);
		hanoi(1, from, to, other);
		hanoi(n - 2, other, from, to);
		hanoi(1, other, to, from);
		hanoi(n - 2, other, to, from);
	}
	else
	{
		hanoi(n - 3, from, other, to);
		hanoi(1, from, other, to);
		hanoi(n - 3, other, to, from);
		hanoi(1, from, other, to);
		hanoi(n - 2, to, from, other);
		hanoi(1, from, to, other);
		hanoi(n - 2, other, from, to);
		hanoi(1, other, to, from);
		hanoi(n - 2, other, to, from);
	}
}


int cnt_hanoi(int n)
{
	if (n == 0)
		return (0);
	return (2 * cnt_hanoi(n - 1) + 1);
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", cnt_hanoi(n));
	hanoi(n, 1, 3, 2);
	return 0;
}