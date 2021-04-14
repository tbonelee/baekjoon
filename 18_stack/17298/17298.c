#include <stdio.h>

// typedef struct s_memo{
// 	int idx;
// 	int num;
// }	t_memo;

int stack[1000001];
int top_n = 0;

void push(int num)
{
	stack[++top_n] = num;
}

int pop(void)
{
	return (stack[top_n--]);
}

int top(void)
{
	return (stack[top_n]);
}

int main()
{
	int N;
	scanf("%d", &N);
	int arr[1000001];
	int memo[1000001];
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		while (top_n != 0 && arr[i] > arr[top()])
		{
			memo[pop()] = arr[i];
		}
		push(i);
	}
	while (top_n != 0)
	{
		memo[pop()] = -1;
	}
	for (int i = 1; i <= N; i++)
	{
		printf("%d ", memo[i]);
	}
	printf("\n");
	return (0);
}