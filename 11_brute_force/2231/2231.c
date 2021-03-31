#include <stdio.h>

int	g_min_value;
int g_min_generator;

int	digit_sum(int n)
{
	if (n < 10)
		return n;
	return (digit_sum(n / 10) + n % 10);
}


int main()
{
	int n;

	scanf("%d", &n);

	g_min_generator = n + 1;
	g_min_value = g_min_generator + digit_sum(g_min_generator);
	int temp;
	for (int i = 1; i < n; i++)
	{
		if ((temp = i + digit_sum(i)) == n
		&& temp < g_min_value)
		{
			g_min_value = temp;
			g_min_generator = i;
			break;
		}
	}
	if (g_min_generator == n + 1)
		g_min_generator = 0;
	printf("%d\n", g_min_generator);
	return 0;
}