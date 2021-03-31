#include <stdio.h>

int g_count_0[41];
int g_count_1[41];

void fibonacci(int n_down, int n_up)
{
	if (n_down == -1)
		return ;
	if (n_up == 0)
	{
		g_count_0[0]++;
		fibonacci(n_down - 1, n_up + 1);
	}
	else if (n_up == 1)
	{
		g_count_1[1]++;
		fibonacci(n_down - 1, n_up + 1);
	}
	else
	{
		g_count_0[n_up] = g_count_0[n_up - 1] + g_count_0[n_up - 2];
		g_count_1[n_up] = g_count_1[n_up - 1] + g_count_1[n_up - 2];
		fibonacci(n_down - 1, n_up + 1);
	}
}
int main()
{
	int T;
	scanf("%d", &T);

	int input[T];

	for (int i = 0; i < T; i++)
		scanf("%d", &input[i]);

	fibonacci(40, 0);

	for (int i = 0; i < T; i++)
		printf("%d %d\n", g_count_0[input[i]], g_count_1[input[i]]);

	return 0;
}

// #include <stdio.h>

// int fibonacci(int n, int arr[][2], int count, int a, int b)
// {
// 	if (n == 0)
// 	{
// 		arr[count][0]++;
// 		return a;
// 	}
// 	else if (n == 1)
// 	{
// 		arr[count][1]++;
// 		return b;
// 	}
// 	else
// 		return (fibonacci(n - 1, arr, count, b, a + b));
// }
// int main()
// {
// 	int T;
// 	scanf("%d", &T);

// 	int input[T];

// 	for (int i = 0; i < T; i++)
// 		scanf("%d", &input[i]);

// 	int arr[T][2];
// 	for (int i = 0; i < T; i++)
// 		for (int j = 0; j < 2; j++)
// 			arr[i][j] = 0;

// 	for (int count = 0; count < T; count++)
// 	{
// 		fibonacci(input[count], arr, count, 0, 1);
// 		printf("%d %d\n", arr[count][0], arr[count][1]);
// 	}
// 	return 0;
// }