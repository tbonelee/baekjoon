#include <stdio.h>

int N, K;

int main()
{
	scanf("%d %d", &N, &K);
	int pos[100001] = {0,};
	int Q[100010];
	int qsize = 100005;
	int head = 1;
	int tail = 1;

	int ret;

	pos[N] = 1;
	Q[tail++] = N;
	while (head != tail)
	{
		int temp = Q[head];
		if (temp == K)
		{
			ret = pos[temp];
			break;
		}
		head = head == qsize ? 1 : head + 1;

		if (temp - 1 >= 0 && pos[temp - 1] == 0)
		{
			Q[tail] = temp - 1;
			tail = tail == qsize ? 1 : tail + 1;
			pos[temp - 1] = pos[temp] + 1;
		}
		if (temp * 2 <= 100000 && pos[temp * 2] == 0 && temp != 0 && temp != 1)
		{
			Q[tail] = temp * 2;
			tail = tail == qsize ? 1 : tail + 1;
			pos[temp * 2] = pos[temp] + 1;
		}
		if (temp + 1 <= 100000 && pos[temp + 1] == 0)
		{
			Q[tail] = temp + 1;
			tail = tail == qsize ? 1 : tail + 1;
			pos[temp + 1] = pos[temp] + 1;
		}

	}
	printf("%d\n", ret - 1);
}