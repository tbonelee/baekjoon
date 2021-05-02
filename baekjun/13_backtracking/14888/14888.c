#include <stdio.h>
#include <stdlib.h>

typedef struct s_info{
	int max;
	int min;
	int cases;
	int count;
	int *results;
	int flag;
}	t_info;

int factorial(int num)
{
	if (num == 0)
		return 1;
	return (num * factorial(num - 1));
}

void find_max_min_and_print(t_info *info)
{
	info->min = info->results[0];
	info->max = info->results[0];

	for (int i = 0; i < info->cases;i++)
	{
		if (info->results[i] < info->min)
			info->min = info->results[i];
		else if (info->results[i] > info->max)
			info->max = info->results[i];
	}
	printf("%d\n%d\n", info->max, info->min);
	info->flag = 1;
}

// void final(int N, int arr[], int operator[], t_info *info)
// {
// 	if (info->count == info->cases && info->flag == 0)
// 	{
// 		find_max_min_and_print(info);
// 		return ;
// 	}
// 	else if (info->count == info->cases && info->flag == 1)
// 	{
// 		return ;
// 	}


// }

void find(int N, int arr[], int operator[], t_info *info, int location, int num)
{
	if (location == N - 1)
	{
		info->results[info->count] = num;
		info->count++;
		return ;
	}

	int temp;
	for (int i = 0; i < 4; i++)
	{
		if (operator[i] != 0)
		{
			if (i == 0)
				temp = num + arr[location + 1];
			else if (i == 1)
				temp = num - arr[location + 1];
			else if (i == 2)
				temp = num * arr[location + 1];
			else
				temp = num / arr[location + 1];
			operator[i]--;
			find(N, arr, operator, info, location + 1, temp);
			operator[i]++;
		}
	}
}


int main()
{
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int operator[4];
	for (int i = 0; i < 4; i++)
		scanf("%d", &operator[i]);

	int cases;
	cases = factorial(N - 1) / factorial(operator[0]) / factorial(operator[1]) / factorial(operator[2]) / factorial(operator[3]);

	int results[cases];

	t_info *info = (t_info *)malloc(sizeof(t_info));
	info->cases = cases;
	info->count = 0;
	info->results = results;
	info->flag = 0;


	find(N, arr, operator, info, 0, arr[0]);

	find_max_min_and_print(info);

	free(info);

	return 0;
}