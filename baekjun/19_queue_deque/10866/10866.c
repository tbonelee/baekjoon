#include <stdio.h>
#include <string.h>

int deck[10010];
int head = 1;
int tail = 1;
int leng = 10005;


int main()
{
	int N, i, temp;
	char str[12];
	for (i = 0, scanf("%d", &N); i < N; i++ )
	{
		scanf("%s", str);
		// printf("i = %d\n", i);
		if (str[0] == 'p')
		{
			if (str[5] == 'f')
			{
				scanf("%d", &temp);
				head = (head == 1) ? leng : head - 1;
				deck[head] = temp;
			}
			else if (str[5] == 'b')
			{
				scanf("%d", &temp);
				deck[tail] = temp;
				tail = (tail == leng) ? 1 : tail + 1;
			}
			else if (str[4] == 'f')
			{
				if (head == tail)
					printf("-1\n");
				else
				{
					printf("%d\n", deck[head]);
					head = (head == leng) ? 1 : head + 1;
				}
			}
			else if (str[4] == 'b')
			{
				if (head == tail)
					printf("-1\n");
				else
				{
					tail = (tail == 1) ? leng : tail - 1;
					printf("%d\n", deck[tail]);
				}
			}
		}
		else if (str[0] == 's')
		{
			// printf("head = %d, tail = %d\n", head, tail);
			int ret;
			if (head <= tail)
			{
				ret = tail - head;
			}
			else
				ret = leng + tail - head;
			printf("%d\n", ret);
		}
		else if (str[0] == 'e')
		{
			printf("%d\n", (head == tail) ? 1 : 0);
		}
		else if (str[0] == 'f')
		{
			if (head == tail)
				printf("-1\n");
			else
				printf("%d\n", deck[head]);
		}
		else if (str[0] == 'b')
		{
			if (head == tail)
				printf("-1\n");
			else
				printf("%d\n", deck[(tail == 1) ? leng : tail - 1]);
		}
	}
}