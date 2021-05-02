// 명령어 받는 것 scanf vs. open?
// scanf(" %5c%d", &arr[i]);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		g_stack[10001];
int		g_size;

void	push(int n);
void	pop(void);
void	size(void);
void	empty(void);
void	top(void);

int main()
{
	int N;
	scanf("%d", &N);
	char	str[6];
	int temp;

	for (int i = 1; i <= N; i++)
	{
		// N을 받으면서 버퍼 마지막에 개행문자 하나 남아있음
		// 이걸 처리해준 다음에 아래의 scanf를 시행해야 함.
		// 그렇지 않으면 버퍼에 들어있는 개행문자를 보고
		// "개행문자 전까지 처리하라 했는데 개행문자가 있네? 그러면 그 앞에 것만 처리해야지"
		// 하는데 버퍼에는 개행문자 앞에 아무 것도 없기 때문에 개행 문자는 그대로 남겨둔 채로
		// 길이 0의 스트링을 처리하고, i는 1 늘어나고
		// 다시 위의 과정을 반복해서 아무 것도 하지 않은채로
		// 이번 for문은 끝나버리게 된다.
		// 그래서 format specifier앞에 공백을 넣어줘서 white space를 처리하도록 했다.
		scanf("%s", str);
		if (str[0] == 'p' && str[1] == 'u')
		{
			scanf("%d", &temp);
			push(temp);
		}
		else if (str[0] == 'p' && str[2] == 'p')
		{
			pop();
		}
		else if (str[0] == 's')
		{
			size();
		}
		else if (str[0] == 'e')
		{
			empty();
		}
		else if (str[0] == 't')
		{
			top();
		}

	}

	return (0);
}

void	push(int n)
{
	g_size++;
	g_stack[g_size] = n;
}

void	pop(void)
{
	if (g_size == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", g_stack[g_size]);
		g_size--;
	}
}

void	size(void)
{
	printf("%d\n", g_size);
}

void	empty(void)
{
	if (g_size == 0)
		printf("1\n");
	else
		printf("0\n");
}

void	top(void)
{
	if (g_size == 0)
		printf("-1\n");
	else
		printf("%d\n", g_stack[g_size]);
}