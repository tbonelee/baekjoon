#include <stdio.h>

int main()
{
	int arr[10];
	for (int i = 1; i <= 9; i++)
		scanf("%d", arr + i);
	int maxnum = 0, maxidx;
	for (int i = 1; i <= 9; i++)
	{
		if (arr[i] > maxnum)
		{
			maxnum = arr[i];
			maxidx = i;
		}
	}
	printf("%d\n%d\n", maxnum, maxidx);
}