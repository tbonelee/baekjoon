#include <stdio.h>
#include <stdlib.h>

typedef struct s_struct {
int age;
char name[101];
}	t_coordinate;


void	only_merge_age(t_coordinate *arr[], int left, int mid, int right)
{
	t_coordinate *temp[right - left + 1];
	int i_left = left;
	int i_right = mid + 1;
	int i_temp = -1;

	for (; i_left <= mid && i_right <= right;)
	{
		if (arr[i_left]->age <= arr[i_right]->age)
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

void	merge_sort_age(t_coordinate *arr[], int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		merge_sort_age(arr, left, mid);
		merge_sort_age(arr, mid + 1, right);
		only_merge_age(arr, left, mid, right);
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
		scanf("%d %s", &arr[i]->age, arr[i]->name);

	merge_sort_age(arr, 0, N - 1);


	for (int i = 0; i < N; i++)
		printf("%d %s\n", arr[i]->age, arr[i]->name);

	for (int i = 0; i < N; i++)
		free(arr[i]);

}