#include <stdio.h>

#define idx(nbr) ((nbr) + 50)

int g_arr[101][101][101];



int rec(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return (1);
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		if (g_arr[idx(a)][idx(b)][idx(c)] == -1)
			g_arr[idx(a)][idx(b)][idx(c)] = rec(20, 20, 20);
		return (g_arr[idx(a)][idx(b)][idx(c)]);
	}
	else if (a < b && b < c)
	{
		if (g_arr[idx(a)][idx(b)][idx(c)] == -1)
			g_arr[idx(a)][idx(b)][idx(c)] = rec(a, b, c - 1) + rec(a, b - 1, c - 1) - rec(a, b - 1, c);
		return (g_arr[idx(a)][idx(b)][idx(c)]);
	}
	else
	{
		if (g_arr[idx(a)][idx(b)][idx(c)] == -1)
			g_arr[idx(a)][idx(b)][idx(c)] = rec(a - 1, b, c) + rec(a - 1, b - 1, c) + rec(a - 1, b, c - 1) - rec(a - 1, b - 1, c - 1);
		return (g_arr[idx(a)][idx(b)][idx(c)]);
	}
}



int main()
{
	// for (int a = - 50; a <= 0; a++)
	// 	for (int b = - 50; b <= 50; b++)
	// 		for (int c = -50; c <= 50; c++)
	// 			g_arr[a + 50][b + 50][c + 50] = 1;
	// for (int a = 1; a <= 50; a++)
	// 	for (int b = -50; b <= 0; b++)
	// 		for (int c = -50; c <= 50; c++)
	// 			g_arr[a + 50][b + 50][c + 50] = 1;
	// for (int a = 1; a <= 50; a++)
	// 	for (int b = 1; b <= 50; b++)
	// 		for (int c = -50; c <= 0; c++)
	// 			g_arr[a + 50][b + 50][c + 50] = 1;
	for (int a = - 50; a <= 50; a++)
		for (int b = - 50; b <= 50; b++)
			for (int c = -50; c <= 50; c++)
				g_arr[idx(a)][idx(b)][idx(c)] = -1;

	// rec(100, -50, 100, -50, 100, -50);
	// printf("here");
	while (1)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, rec(a, b, c));

	}

	return 0;

}