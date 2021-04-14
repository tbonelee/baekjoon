#include <stdio.h>

// int Q[1001];
// int head = 1;
// int tail = 1;
// int qleng = 1000;

// void	enque(int num)
// {
// 	Q[tail] = num;
// 	if (tail == qleng)
// 		tail = 1;
// 	else
// 		tail++;
// }

// int		deque(void)
// {
// 	int ret = Q[head];
// 	if (head == qleng)
// 		head = 1;
// 	else
// 		head++;
// }

// void	entail(int where)
// {
// 	if (head <= tail)
// }

// int		deque_nth(int n)
// {
// 	int ret;
// 	if (head <= tail)
// 	{
// 		if (tail - head >= n)
// 		{

// 		}
// 		else
// 		ret = Q[head + n - 1];
// 		entail(head + n - 1);
// 	}
// 	else
// 	{
// 		ret = Q[((head - 2) + n) % qleng + 1];
// 		entail(((head - 2) + n) % qleng + 1);
// 	}
// }

int main()
{
	int N,K;
	scanf("%d %d", &N, &K);
	int arr[1001];
	int cnt = 1;
	int count_K = 0;
	for (int i = 1; i <= N; i++)
	{
		arr[i] = 1;
	}
	printf("<");
	int i = 1;
	while (1)
	{
		if (arr[i] == 1)
		{
			if (cnt == K)
			{
				printf("%d", i);
				arr[i] = 0;
				count_K++;
				if (count_K == N)
					break ;
				else
					printf(", ");

				cnt = 1;
				i = (i != N ? i + 1 : 1);
			}
			else
			{
				cnt++;
				i = (i != N ? i + 1 : 1);
			}
		}
		else if (arr[i] == 0)
		{
			// printf("arr[i] = 0 at %d\n", i);
			i = (i != N ? i + 1 : 1);
		}
	}
	printf(">\n");
	return 0;
}