#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int arr[500001], head = 1, tail = N;
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}
	while (head != tail)
	{
		head = head != 500000 ? head + 1 : 1;
		if (tail != 500000)
		{
			arr[++tail] = arr[head];
			head = head != 500000 ? head + 1 : 1;
		}
		else
		{
			tail = 1;
			arr[tail] = arr[head];
			head = head != 500000 ? head + 1 : 1;
		}
	}
	printf("%d\n", arr[head]);
	return 0;
}