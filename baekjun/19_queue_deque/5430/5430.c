#include <stdio.h>

int qleng = 100005;

void find(char order[], int n, int arr[]);

int main()
{
	int T; scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		char order[100005]; scanf("%s", order);
		int n; scanf("%d", &n);
		int arr[100006];
		scanf(" %c", &order[100005]);
		for (int j = 0; j < n; j++)
			scanf("%d,", &arr[j]);
		getchar();
		// for (int j = 0; j < n; j++)
		// 	printf("%d ", arr[j]);
		// printf("%c", order[100001]);

		find(order, n, arr);
	}
}

void pop_head(int *head, int *size);
void pop_tail(int *tail, int *size);
void print_arr(int arr[], int rev_flag, int head, int tail);
void find(char order[], int n, int arr[])
{
	int rev_flag = 0;
	int head = 0, tail = n - 1, size = n;

	for (int i = 0; order[i]; i++)
	{
		if (order[i] == 'R')
			rev_flag = (rev_flag == 0 ? 1 : 0);
		else if (order[i] == 'D')
		{
			if (size == 0)
			{
				printf("error\n");
				return ;
			}
			if (rev_flag == 0)
				pop_head(&head, &size);
			else
				pop_tail(&tail, &size);
		}
	}
	print_arr(arr, rev_flag, head, tail);
}

void print_arr(int arr[], int rev_flag, int head, int tail)
{
	int i;
	printf("[");
	if (head == tail + 1)
	{

	}
	else if (rev_flag == 0)
	{
		if (head <= tail)
		{
			for (i = head; i < tail; i++)
			{
				printf("%d,", arr[i]);
			}
			printf("%d", arr[i]);
		}
		else
		{
			for (i = head; i <= qleng; i++)
			{
				printf("%d,", arr[i]);
			}
			for (i = 1; i < tail; i++)
			{
				printf("%d,", arr[i]);
			}
			printf("%d", arr[i]);
		}
	}
	else
	{
		if (head <= tail)
		{
			for (i = tail; i > head; i--)
			{
				printf("%d,", arr[i]);
			}
			printf("%d", arr[i]);
		}
		else
		{
			for (i = tail; i >= 1; i--)
			{
				printf("%d,", arr[i]);
			}
			for (i = qleng; i > head; i--)
			{
				printf("%d,", arr[i]);
			}
			printf("%d", arr[i]);
		}

	}
	printf("]\n");
}

void pop_head(int *head, int *size)
{
	if (*head == qleng)
	{
		*head = 1;
	}
	else
	{
		*head = *head + 1;
	}
	*size = *size - 1;
}
void pop_tail(int *tail, int *size)
{
	if (*tail == 1)
	{
		*tail = qleng;
	}
	else
	{
		*tail = *tail - 1;
	}
	*size = *size - 1;
}