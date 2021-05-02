// 알고리즘을 짜서 문제를 해결하려 했으나 경우의 수가 너무 많아져서 복잡해짐.
// 포기하고 찾아 봤더니 보통은 브루트포스로 풀더라..

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m;

// 괜찮으면 클릭해야 되는 버튼 횟수, 안 괜찮으면 0
int isok(int arr[], int num)
{
	if (num == 0)
	{
		if (arr[0] == -1)
			return 0;
		else
			return 1;
	}
	int len = 0;
	while (num)
	{
		if (arr[num % 10] == -1)
			return 0;
		len++;
		num /= 10;
	}
	return len;
}

int digit(int num)
{
	if (num == 0)
		return 1;
	int i = 0;
	for ( ; num != 0; i++ )
	{
		num /= 10;
	}
	return i;
}

int main()
{
	// char str[7];
	// scanf("%s", str);
	scanf("%d", &n);
	scanf("%d", &m);
	int arr[10];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < m; i++)
	{
		int temp; scanf("%d", &temp);
		arr[temp] = -1;
	}
	// printf("===================\n");

	int min = 1000000000;
	if ((n < 100 ? 100 - n : n - 100) < min)
		min = (n < 100 ? 100 - n : n - 100);
	for (int i = (n - min > 0 ? n - min : 0); i <= n + min; i++)
	{
		int len = isok(arr, i);
		int temp = (n < i ? i - n : n - i) + len;
		if (len > 0 && temp < min)
			min = temp;

		// int temp = isok(arr, i) + (n < i ? i - n : n - i);
		// if (isok(arr, i) > 0 && temp < min)
		// 	min = temp;
	}
	printf("%d\n", min);

}