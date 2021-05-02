#include <stdio.h>

int main()
{
	int N, temp;
	scanf("%d", &N);
	char str[6];
	int q[2000001];
	int head = 1, tail = 1;
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", str);
		if (str[1] == 'u')
		{
			scanf("%d", &temp);
			q[tail] = temp;
			tail = (tail == 2000000 ? 1 : tail + 1);
		}
		else if (str[1] == 'o')
		{
			printf("%d\n", head != tail ? q[head] : -1);
			if (head != tail)
				head = (head == 2000000 ? 1 : head + 1);
		}
		else if (str[1] == 'i')
		{
			printf("%d\n", tail >= head ? tail - head : 2000000 - head + 1 + tail);
		}
		else if (str[1] == 'm')
		{
			printf("%d\n", head == tail ? 1 : 0);
		}
		else if (str[1] == 'r')
		{
			printf("%d\n", head != tail ? q[head] : -1);
		}
		else
		{
			printf("%d\n", head != tail ? q[tail - 1] : -1);
		}
	}
	return 0;
}