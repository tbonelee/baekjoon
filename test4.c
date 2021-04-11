#include <stdio.h>

void	push(int n, int stack[], int size);
void	size(int *size);
void	empty(int *size);
void	top(int stack[], int *size);

int main()
{
	int N;
	scanf("%d", &N);
	char	str[6];
	int temp;
    int stack[10000];
    int stacksize = -1;

	for (int i = 1; i <= N; i++)
	{

		scanf("%s", str);
		if (str[0] == 'p' && str[1] == 'u')
		{
			scanf("%d", &temp);
			stacksize++;
			push(temp, stack, stacksize);
		}
		else if (str[0] == 'p' && str[2] == 'p')
		{
			if (stacksize == -1)
				printf("-1\n");
			else
			{
				printf("%d\n", stack[stacksize]);
				stacksize--;
			}
		}
		else if (str[0] == 's')
			size(&stacksize);
		else if (str[0] == 'e')
			empty(&stacksize);
		else if (str[0] == 't')
			top(stack, &stacksize);
	}

	return (0);
}

void	push(int n, int stack[], int size)
{
	stack[size] = n;
}

void	size(int *size)
{
	printf("%d\n", *size + 1);
}

void	empty(int *size)
{
	if (*size == -1)
		printf("1\n");
	else
		printf("0\n");
}

void	top(int stack[], int *size)
{
	if (*size == -1)
		printf("-1\n");
	else
		printf("%d\n", stack[*size]);
}