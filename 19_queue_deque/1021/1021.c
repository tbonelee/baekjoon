#include <stdio.h>

int q[60];
int q_size = 0;
int q_leng = 55;
int head = 1;
int tail = 1;

void pushback(void)
{
	if (head == tail) // 큐가 빈 상황이라 여기 걸리진 않을테지만 혹시 모르니
		return ;
	if (head == q_leng)
	{
		// printf("1\n");
		q[tail++] = q[head];
		head = 1;
	}
	else
	{
		if (tail == q_leng)
		{
			// printf("2\n");
			q[tail] = q[head++];
			tail = 1;
		}
		else
		{
			// printf("3\n");
			q[tail++] = q[head++];
		}
	}
}

void pop(void)
{
	if (head == tail)
		return ;
	if (head == q_leng)
		head = 1;
	else
		head++;
}

void rearr(int i)
{
	for (int j = head; j < i; j++)
		pushback();
	pop();
}

int search_dist_rearr(int n)
{
	int i, ret;
	int flag = 0;
	int temp_tail;
	if (head <= tail)
	{
		for (i = head; i < tail; i++)
			if (q[i] == n)
				break;
		temp_tail = tail;

	}
	else
	{
		// printf("else\n");
		for (i = head; i <= q_leng; i++)
			if (q[i] == n)
			{
				flag = 1;
				break;
			}
		if(flag == 0)
			for (i = 1; i < tail; i++ )
			{
				// printf(">?\n");
				if (q[i] == n)
					break ;
			}
		temp_tail = tail + q_leng;
		i = (flag == 0) ? i + q_leng : i;

	}
	if ((i - head) <= temp_tail - i )
	{
		// printf("ther, i = %d, head = %d, temp_tail = %d\n", i, head, temp_tail);
		ret = i - head;
	}
	else
	{
		// printf("here, i = %d, head = %d, temp_tail = %d\n", i, head, temp_tail);
		ret = temp_tail - i;
	}
	rearr(i);
	return (ret);

}

int main()
{
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		q[i] = i;
	}
	q_size = N;
	head = 1; tail = N + 1;

	int result = 0;
	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &temp);
		result += search_dist_rearr(temp);
		// printf("num = %d, result = %d, q[head] = %d, q[tail - 1] = %d\n", temp, result, q[head], q[tail - 1]);

	// printf("\n");
	}
	printf("%d\n", result);
}

// int main()
// {
// 	int q_size = 5;
// 	head = 54; tail = 4;
// 	q[54] = 1; q[55] = 2; q[1] = 3; q[2] = 4; q[3] = 5;
// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("head before = %d\n", head);
// 		pushback();
// 		printf("head after = %d\n", head);
// 		pop();
// 	}
// 	for (int i = head; i <= q_leng; i++)
// 		printf("q[%d] = %d\n", i,q[i]);
// 	for (int i = 1; i < tail; i++)
// 		printf("q[%d] = %d\n", i,q[i]);
// }