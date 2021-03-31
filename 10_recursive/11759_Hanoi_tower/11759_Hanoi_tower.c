#include <stdio.h>

void	hanoi(int n, int from, int to, int other)
{
	if (n == 0)
		return ;
	hanoi(n - 1, from, other, to);
	printf("%d %d\n", from, to);
	hanoi(n - 1, other, to, from);
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