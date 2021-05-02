#include <stdio.h>

char stack[51];
int top = 0;
// char stack2[101];
// int top2 = 0;


void	push(char input)
{
	stack[++top] = input;
}

char	pop(void)
{
	return	stack[top--];
}
// void	push2(char input)
// {
// 	stack2[++top2] = input;
// }

// char	pop2(void)
// {
// 	return	stack2[top2--];
// }

int main()
{
	char temp[101];
	while (1)
	{
		scanf("%[^\n]s", temp);
		int i;
		if (temp[0] == '.' && temp[1] == 0)
			return 0;
		for (i = 0; temp[i]; i++)
		{

			if (temp[i] == '(' || temp[i] == '[')
			{
				push(temp[i]);
			}
			else if (temp[i] == ')')
			{
				if (top == 0)
				{
					break ;
				}
				else
				{
					if (pop() != '(')
					{
						break ;
					}
				}
			}
			else if (temp[i] == ']')
			{
				if (top == 0)
				{
					break ;
				}
				else
				{
					if (pop() != '[')
					{
						break ;
					}
				}
			}
		}
		if (temp[i] == 0 && top == 0)
			printf("yes\n");
		else
			printf("no\n");
		top = 0;
		getchar();
	}


	// for (int i = 0; i < T; i++)
	// {
	// 	scanf("%s", temp);
	// 	int i;
	// 	for (i = 0; temp[i]; i++)
	// 	{

	// 		if (temp[i] == '(')
	// 		{
	// 			push(temp[i]);
	// 		}
	// 		else if (temp[i] == ')')
	// 		{
	// 			if (top == 0)
	// 			{
	// 				break ;
	// 			}
	// 			else
	// 			{
	// 				if (pop() != '(')
	// 				{
	// 					break ;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	if (temp[i] == 0 && top == 0)
	// 		printf("YES\n");
	// 	else
	// 		printf("NO\n");

	// 	top = 0;
	// }
}