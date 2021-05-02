#include <stdio.h>

void init_fill_counting(int arr[], int counting[], int N, int min, int max)
{
	for (int i = 0; i < max - min + 1; i++)
		counting[i] = 0;
	for (int i = 0; i < N; i++)
		counting[arr[i] - min]++;
}

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


int median(int arr[], int N)
{
	merge_sort(arr, 0, N - 1);

	// if (N % 2 = 1)
		return (arr[N / 2]);
	// N이 짝수도 있으면 아래와 같은 정의 필요하지만 문제에서 배제
	// else
	// 	return (arr[(double)(arr[N / 2] + arr[N / 2 - 1]) / 2]);

}

int mean(int arr[], int N)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += arr[i];

	long double mean = (long double)sum / (long double)N;

	if (mean >= 0)
	{
		if (mean - (int)mean >= 0.5)
			return ((int)mean + 1);
		else
			return ((int)mean);
	}
	else if (mean <= -2147483647)
	{
		if (mean - (int)mean <= 0.5)
			return ((int)mean - 1);
		else
			return ((int)mean);
	}
	else
	{
		mean *= -1;
		if (mean - (int)mean >= 0.5)
			return ((-1) * ((int)mean + 1));
		else
			return ((-1) * (int)mean);
	}
}

int mode(int arr[], int N)
{
	int min = arr[0], max = arr[N - 1];
	int counting[max - min + 1];
	init_fill_counting(arr, counting, N, min, max);


	int num = 0; // 가장 많이 나오는 숫자의 갯수
	int for_check_repetition[max - min + 1]; // 최빈값이 두 개 이상인 경우를 대비
	for (int i = 0; i < max - min + 1; i++)
		for_check_repetition[i] = 0;
	for (int i = 0; i < max - min + 1; i++)
		if (counting[i] >= num)
		{
			num = counting[i];
			for_check_repetition[i] = num;
		}

	int first = 0;
	int first_idx;
	int second_and_over = 0;
	for (int i = 0; i < max - min + 1; i++)
		if (for_check_repetition[i] == num && first == 0)
		{
			first++;
			first_idx = i;
		}
		else if (for_check_repetition[i] == num && first == 1)
			return (min + i);
	return (min + first_idx);
}

int range(int arr[], int N)
{
	return (arr[N - 1] - arr[0]);
}

int main()
{
	int N;
	scanf("%d", &N);

	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", mean(arr, N));

	printf("%d\n", median(arr, N));

	printf("%d\n", mode(arr, N));

	printf("%d\n", range(arr, N));
}