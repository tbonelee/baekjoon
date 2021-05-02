// 수를 오름차순으로 정렬
// 양수 중 가장 큰 수부터 두 개씩 묶기
// 음수 중 가장 작은 수부터 두 개씩 묶기
// sum

#include <stdio.h>
#include <string.h>
#include <limits.h>

void	mergesort_asc(int arr[], int start, int end);
void	merge_asc(int arr[], int start, int mid, int end);
void	mergesort_des(int arr[], int start, int end);
void	merge_des(int arr[], int start, int mid, int end);

int main()
{
	int N; scanf("%d", &N);
	int arr_neg[10005], arr_pos[10005];
	int j = 1, k = 1;
	int sum = 0, temp;
	int flag_zero = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &temp);
		if (temp < 0)
			arr_neg[j++] = temp;
		else if (temp > 1)
			arr_pos[k++] = temp;
		else if (temp == 1)
			sum++;
		else
			flag_zero = 1;
	}
	mergesort_asc(arr_neg, 1, j - 1);
	for (int i = 1; i <= j - 1; i++)
	{
		if (i != 1 && arr_neg[i] < arr_neg[i - 1])
		{
			printf("sort_asc fail\n");
			return 0;
		}

	}
	mergesort_des(arr_pos, 1, k - 1);
	for (int i = 1; i <= k - 1; i++)
	{
		if (i != 1 && arr_pos[k] > arr_pos[k - 1])
		{
			printf("sort_des fail\n");
			return 0;
		}

	}
	j--; k--;
	if (j % 2 == 1)
	{
		if (flag_zero == 0)
			sum += arr_neg[j];
		j--;
	}
	if (k % 2 == 1)
		sum += arr_pos[k--];

	for (; j >= 1; j--)
		if (j % 2 == 1)
			sum += arr_neg[j] * arr_neg[j + 1];
	for (; k >= 1; k--)
		if (k % 2 == 1)
			sum += arr_pos[k] * arr_pos[k + 1];

	printf("%d\n", sum);

	return (0);

}

void	mergesort_asc(int arr[], int start, int end)
{
	if (start >= end)
		return ;

	int mid = (start + end) / 2;
	mergesort_asc(arr, start, mid);
	mergesort_asc(arr, mid + 1, end);
	merge_asc(arr, start, mid, end);
}

void	merge_asc(int arr[], int start, int mid, int end)
{
	int max = INT_MAX;
	int temp1[10001];
	int temp2[10001];
	int i = start;
	for (; i <= mid; i++)
	{
		temp1[i] = arr[i];
	}
	temp1[i] = max;

	int j = mid + 1;
	for (; j <= end; j++)
	{
		temp2[j] = arr[j];
	}
	temp2[j] = max;

	int idx = start;
	for (i = start, j = mid + 1; !(i >= mid + 1 && j >= end + 1); idx++)
	{
		if (temp1[i] <= temp2[j])
		{
			arr[idx] = temp1[i++];
		}
		else
		{
			arr[idx] = temp2[j++];
		}
	}
}
void	mergesort_des(int arr[], int start, int end)
{
	if (start >= end)
		return ;

	int mid = (start + end) / 2;
	mergesort_des(arr, start, mid);
	mergesort_des(arr, mid + 1, end);
	merge_des(arr, start, mid, end);
}

void	merge_des(int arr[], int start, int mid, int end)
{
	int min = INT_MIN;
	int temp1[10001];
	int temp2[10001];
	int i = start;
	for (; i <= mid; i++)
	{
		temp1[i] = arr[i];
	}
	temp1[i] = min;

	int j = mid + 1;
	for (; j <= end; j++)
	{
		temp2[j] = arr[j];
	}
	temp2[j] = min;

	int idx = start;
	i = start, j = mid + 1;
	for (; !(i >= mid + 1 && j >= end + 1); idx++)
	{
		if (temp1[i] >= temp2[j])
		{
			arr[idx] = temp1[i++];
		}
		else
		{
			arr[idx] = temp2[j++];
		}
	}
}
