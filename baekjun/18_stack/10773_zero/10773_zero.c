#include <stdio.h>


int main()
{
	int stack[100000] = {0,};
	int size = -1;
	int K, temp[100001];
	scanf("%d", &K);
	int ret = 0;
	for (int i = 1; i <= K; i++)
	{
		scanf("%d", &temp[i]);

	}
	for (int i = 1; i <= K; i++)
	{
		if (temp[i] == 0)
		{
			size--;
		}
		else
		{
			stack[++size] = temp[i];
		}
	}
	for (int i = 0; i <= size; i++)
	{
		ret += stack[i];
	}
	printf("%d\n", ret);

	return (0);
}