#include <stdio.h>

void	find(int input[], int N, int M);

int main()
{
	int T; scanf("%d", &T);
	int input[101];
	int N, M;
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &input[j]);
		}
		find(input, N, M);
	}

}

void	push_back(int q[], int *head, int *tail, int q_leng)
{
	*tail = (*tail + 1 == q_leng) ? 0 : *tail + 1;
	q[*tail] = q[*head];
	*head = (*head + 1 == q_leng) ? 0 : *head + 1;
}

void	pop(int *head, int q_leng)
{
	*head = (*head + 1 == q_leng) ? 0 : *head + 1;
}

void	find(int input[], int N, int M)
{
	int q[101], q_leng = 100, head = 0, tail = N - 1;
	int prior[10] = {0,};
	for (int j = 0; j < N; j++)
	{
		q[j] = j;
		prior[input[q[j]]]++;
		// printf("q[%d] = %d\n", j, q[j]);
	}
	// for (int j = 1; j <= 9; j++)
	// 	printf("prior[%d] = %d\n", j, prior[j]);
	int cnt = 0;
	// printf("q[head] = %d, input[q[head]] = %d\n", q[head], input[q[head]]);
	while (1)
	{
		int ok_to_pop = 1;
		for (int i = input[q[head]] + 1; i <= 9; i++)
		{
			if (prior[i] != 0)
			{
				ok_to_pop = 0;
				break ;
			}
		}
		// printf("q[head] = %d, ok_to_pop = %d\n", q[head], ok_to_pop);
		if (ok_to_pop == 1)
		{
			// printf("in");
			cnt++;
			if (q[head] == M)
			{
				// printf("break\n");
				break ;
			}
			else
			{
				prior[input[q[head]]]--;
				pop(&head, q_leng);
			}
		}
		else
		{
			push_back(q, &head, &tail, q_leng);
			// printf("pushback\n");
		}
	}

	printf("%d\n", cnt);
}












// void	find(int q[], int N, int M)
// {
// 	// int index[100];
// 	int to_find_value = q[M];
// 	int	larger_num = 0;
// 	int the_last_larger_idx = -1;
// 	int identical_num_before_M = 0;
// 	// int head = 0, tail = N - 1;
// 	for (int j = 0; j < N; j++)
// 	{
// 		if (q[j] > to_find_value)
// 		{
// 			larger_num++;
// 			the_last_larger_idx = j;
// 		}
// 	}

// 	if (the_last_larger_idx == -1)
// 	{
// 		for (int j = 0; j < M; j++)
// 		{
// 			if (q[j] == to_find_value)
// 				identical_num_before_M++;
// 		}
// 	}
// 	else if (M < the_last_larger_idx)
// 	{
// 		for (int j = 0; j < N; j++)
// 		{
// 			if ((j < M || j >= the_last_larger_idx)
// 			&& q[j] == to_find_value)
// 				identical_num_before_M++;
// 		}

// // 		printf("here, id_num_before_M = %d, tlli = %d\n
// // larger_num = %d\n", identical_num_before_M, the_last_larger_idx, larger_num);

// 	}
// 	else if (M > the_last_larger_idx)
// 	{
// 		for (int j = the_last_larger_idx + 1; j < M; j++)
// 		{
// 			if (q[j] == to_find_value)
// 				identical_num_before_M++;
// 		}
// 	}
// 	printf("%d\n", larger_num + identical_num_before_M + 1);



// 	// for (int j = 0; j < N; j++)
// 	// {./a
// 	// 	if (j < the_last_larger_idx)
// 	// 	{

// 	// 	}
// 	// }

// }