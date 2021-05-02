#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool ispossible[100001];
int	stack[100002];
int top_n = 0;
int cnt = 0;

void	push(int num)
{
	stack[++top_n] = num;
}

int		pop(void)
{
	return (stack[top_n--]);
}

int		top(void)
{
	return (stack[top_n]);
}

int main()
{
	char out[250005];
	int n; scanf("%d", &n);
	int to_put;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &to_put);
		if (top() < to_put)
		{
			int j;
			for (j = top() + 1; j <= to_put; j++)
			{
				if (ispossible[j] == false)
				{
					ispossible[j] = true;
					out[cnt++] = '+';
					push(j);
				}
			}
			out[cnt++] = '-';
			pop();

		}
		else if (top() > to_put)
		{
			int j;
			for (j = top(); j > to_put; j--)
			{
				if (ispossible[j] == true)
				{
					out[cnt++] = 'n';
				}

			}
			out[cnt++] = '-';
			pop();
		}
		else
		{
			out[cnt++] = '-';
			pop();
		}
	}
	out[cnt] = 0;
	int no_flag = 0;
	for (int i = 0; out[i]; i++)
	{
		if (out[i] == 'n')
			no_flag = 1;
	}
	if (no_flag == 1)
	{	printf("NO\n");	return 0;}
	for (int i = 0; out[i]; i++)
	{
		printf("%c\n", out[i]);
	}
	return 0;
}