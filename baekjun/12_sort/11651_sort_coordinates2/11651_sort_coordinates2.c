#include <stdio.h>
#include <stdlib.h>

typedef struct s_struct {
int x;
int y;
}	t_coordinate;


void	only_merge_x(t_coordinate *arr[], int left, int mid, int right)
{
	t_coordinate *temp[right - left + 1];
	int i_left = left;
	int i_right = mid + 1;
	int i_temp = -1;

	for (; i_left <= mid && i_right <= right;)
	{
		if (arr[i_left]->x <= arr[i_right]->x)
			temp[++i_temp] = arr[i_left++];
		else
			temp[++i_temp] = arr[i_right++];
	}

	if (i_left > mid)
		while (i_right <= right)
			temp[++i_temp] = arr[i_right++];
	else
		while (i_left <= mid)
			temp[++i_temp] = arr[i_left++];

	for (i_temp = 0; i_temp < right - left + 1; i_temp++)
		arr[left + i_temp] = temp[i_temp];
}

void	merge_sort_x(t_coordinate *arr[], int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		merge_sort_x(arr, left, mid);
		merge_sort_x(arr, mid + 1, right);
		only_merge_x(arr, left, mid, right);
	}
}

void	only_merge_y(t_coordinate *arr[], int left, int mid, int right)
{
	t_coordinate *temp[right - left + 1];
	int i_left = left;
	int i_right = mid + 1;
	int i_temp = -1;

	for (; i_left <= mid && i_right <= right;)
	{
		if (arr[i_left]->y <= arr[i_right]->y)
			temp[++i_temp] = arr[i_left++];
		else
			temp[++i_temp] = arr[i_right++];
	}

	if (i_left > mid)
		while (i_right <= right)
			temp[++i_temp] = arr[i_right++];
	else
		while (i_left <= mid)
			temp[++i_temp] = arr[i_left++];

	for (i_temp = 0; i_temp < right - left + 1; i_temp++)
		arr[left + i_temp] = temp[i_temp];
}

void	merge_sort_y(t_coordinate *arr[], int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		merge_sort_y(arr, left, mid);
		merge_sort_y(arr, mid + 1, right);
		only_merge_y(arr, left, mid, right);
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	t_coordinate *arr[N];
	for (int i = 0; i < N; i++)
		arr[i] = (t_coordinate *)malloc(sizeof(t_coordinate));
	for (int i = 0; i < N; i++)
		scanf("%d %d", &arr[i]->x, &arr[i]->y);

	merge_sort_y(arr, 0, N - 1);

	int start, end;
	for (int i = 0; i < N; i++)
	{
		start = i, end = i;
		for (; arr[i]->y == arr[i + 1]->y; i++)
			end = i + 1;
		merge_sort_x(arr, start, end);
	}

	for (int i = 0; i < N; i++)
		printf("%d %d\n", arr[i]->x, arr[i]->y);

	for (int i = 0; i < N; i++)
		free(arr[i]);

}