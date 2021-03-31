#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void	only_merge_lexico(char arr[][51], int left, int mid, int right)
{
	char temp[right - left + 1][51];
	int i_left = left;
	int i_right = mid + 1;
	int i_temp = -1;

	for (; i_left <= mid && i_right <= right;)
	{
		if (strcmp(arr[i_left], arr[i_right]) < 0)
			strcpy(temp[++i_temp], arr[i_left++]);
		else
			strcpy(temp[++i_temp], arr[i_right++]);
	}

	if (i_left > mid)
		while (i_right <= right)
			strcpy(temp[++i_temp], arr[i_right++]);
	else
		while (i_left <= mid)
			strcpy(temp[++i_temp], arr[i_left++]);

	for (i_temp = 0; i_temp < right - left + 1; i_temp++)
		strcpy(arr[left + i_temp], temp[i_temp]);
}

void	merge_sort_lexico(char arr[][51], int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		merge_sort_lexico(arr, left, mid);
		merge_sort_lexico(arr, mid + 1, right);
		only_merge_lexico(arr, left, mid, right);
	}
}

void	only_merge_length(char arr[][51], int left, int mid, int right)
{
	char temp[right - left + 1][51];
	int i_left = left;
	int i_right = mid + 1;
	int i_temp = -1;

	for (; i_left <= mid && i_right <= right;)
	{
		if (strlen(arr[i_left]) < strlen(arr[i_right]))
			strcpy(temp[++i_temp], arr[i_left++]);
		else
			strcpy(temp[++i_temp], arr[i_right++]);
	}

	if (i_left > mid)
		while (i_right <= right)
			strcpy(temp[++i_temp], arr[i_right++]);
	else
		while (i_left <= mid)
			strcpy(temp[++i_temp], arr[i_left++]);

	for (i_temp = 0; i_temp < right - left + 1; i_temp++)
		strcpy(arr[left + i_temp], temp[i_temp]);
}

void	merge_sort_length(char arr[][51], int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		merge_sort_length(arr, left, mid);
		merge_sort_length(arr, mid + 1, right);
		only_merge_length(arr, left, mid, right);
	}
}

void delete_and_pull(char arr[][51], int N, int index)
{
	for (int i = index; i + 1 < N; i++)
		strcpy(arr[i], arr[i + 1]);
}

int main()
{
	int N;
	scanf("%d", &N);

	char arr[N][51];
	for (int i = 0; i < N; i++)
	{
		// arr[i] = (char *)malloc(50);
		scanf("%s", arr[i]);
		// printf("%s\n", arr[i]);
	}
	merge_sort_length(arr, 0, N - 1);

	int start, end;
	for (int i = 0; i < N; i++)
	{
		start = i, end = i;
		for (; strlen(arr[i]) == strlen(arr[i + 1]); i++)
			end = i + 1;
		merge_sort_lexico(arr, start, end);
	}

	// printf("here\n");
	// for (int i = 0; i < N; i++)
	// {
	// 	printf("%s\n", arr[i]);
	// }

	// printf("finish\n");

	int N_temp = N;
	for (int i = 0; i + 1 < N_temp; i++)
	{
		for (; strcmp(arr[i], arr[i + 1]) == 0 && i + 1 < N_temp;)
		{
			delete_and_pull(arr, N_temp, i + 1);
			// free(arr[N_temp - 1]);
			N_temp -= 1;
		}
	}

	// printf("N = %d, N_temp = %d\n", N, N_temp);

	for (int i = 0; i < N_temp; i++)
		printf("%s\n", arr[i]);
	// for (int i = 0; i < N_temp; i++)
	// 	free(arr[i]);
	return 0;
}
