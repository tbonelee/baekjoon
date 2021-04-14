// 수를 오름차순으로 정렬
// 양수 중 가장 큰 수부터 두 개씩 묶기
// 음수 중 가장 작은 수부터 두 개씩 묶기
// sum

#include <stdio.h>
#include <string.h>
#include <limits.h>

void	mergesort(int arr[], int start, int end);
void	merge(int arr[], int start, int mid, int end);

int main()
{
	int N; scanf("%d", &N);
	int arr[10001];
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	mergesort(arr, 1, N);
	int i = 1;
	int sum = 0;
	for (; arr[i] < 0; i++)
		if ((i & 1) == 0)
			sum += arr[i] * arr[i - 1];
	if (arr[i] == 0 && (i & 1) == 0)
	{
		for (; arr[i] == 0; i++)
			;
	}
	else if (arr[i] != 0 && (i & 1) == 0)
	{
		sum += arr[i - 1];
	}
	else if (arr[i] == 0 && (i & 1) != 0)
	{
		for (; arr[i] == 0; i++)
			;
	}

	for (; arr[i] == 1; i++)
	{
		sum += arr[i];
	}

	int isNeven = 0; if ((N & 1) == 0) isNeven = 1;
	int j = N;
	for (; j >= i; j--)
		if ((j & 1) == isNeven)
			sum += arr[j] * arr[j + 1];
	if ((j & 1) == isNeven)
		sum += arr[j + 1];
	printf("%d\n", sum);

	return (0);

}

void	mergesort(int arr[], int start, int end)
{
	if (start == end)
		return ;

	int mid = (start + end) / 2;
	mergesort(arr, start, mid);
	mergesort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

void	merge(int arr[], int start, int mid, int end)
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
	for (i = start, j = mid + 1; (i != mid + 1 || j != end + 1); idx++)
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
