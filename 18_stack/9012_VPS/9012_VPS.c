#include <stdio.h>

char stack[51];
int top = 0;

void	push(char input)
{
	stack[++top] = input;
}

char	pop(void)
{
	return	stack[top--];
}

int main()
{
	int T; scanf("%d", &T);
	char temp[51];
	for (int i = 0; i < T; i++)
	{
		scanf("%s", temp);
		int i;
		for (i = 0; temp[i]; i++)
		{
			// if (temp[i] == '\n')
			// {
			// 	if (top == 0)
			// 		printf("YES\n");
			// 	else
			// 		printf("NO1\n");
			// 	break;
			// }
			if (temp[i] == '(')
			{
				// printf("top = %d, push\n", top + 1);
				push(temp[i]);
			}
			else if (temp[i] == ')')
			{
				if (top == 0)
				{
					// printf("NO2\n");
					break ;
				}
				else
				{
					if (pop() != '(')
					{
						// printf("NO\n");
						break ;
					}
				}
			}
		}
		if (temp[i] == 0 && top == 0)
			printf("YES\n");
		else
			printf("NO\n");

		top = 0;
	}
}