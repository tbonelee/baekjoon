#include <stdio.h>

void	only_merge(int arr[], int left, int mid, int right)
{
	int temp[right - left + 1];
	int i_left = left;
	int i_right = mid + 1;
	int i_temp = -1;

	for (; i_left <= mid && i_right <= right;)
	{
		if (arr[i_left] < arr[i_right])
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

void	merge_sort(int arr[], int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		only_merge(arr, left, mid, right);
	}
}

int check_digit(int n)
{
	int digit = 0;

	for (int i = 0; n != 0; n /= 10)
		digit++;
	return digit;
}

int main()
{
	int n;
	scanf("%d", &n);

	int digit = check_digit(n);

	int arr[digit];

	for (int i = 0; i < digit; i++, n /= 10)
		arr[i] = n % 10;

	merge_sort(arr, 0, digit - 1);
	for (int i = digit - 1; i >= 0; i--)
		printf("%d", arr[i]);
}