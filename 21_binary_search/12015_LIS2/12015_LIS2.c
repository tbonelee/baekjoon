#include <stdio.h>
#include <limits.h>

int N;
int arr[1000001];
int size;
int last_of_active[1000001] = {-1,};

int find(int tofind, int arr[], int start, int end);

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", arr + i);

	for (int i = 1; i <= N; i++)
	{
		if (arr[i] > last_of_active[size])
		{
			last_of_active[++size] = arr[i];
		}
		else if (arr[i] < last_of_active[size])
		{
			int pos = find(arr[i], last_of_active, 1, size);
			last_of_active[pos] = arr[i];
		}
	}
	printf("%d\n", size);
}


int find(int tofind, int arr[], int start, int end)
{
	int memo = INT_MAX;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (tofind <= arr[mid])
		{
			if (mid < memo)
				memo = mid;
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}

	}
	return memo;
}