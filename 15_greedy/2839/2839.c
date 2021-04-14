#include <stdio.h>
#include <limits.h>

int main()
{
	int N;
	scanf("%d", &N);
	int i = N / 5;
	int min = INT_MAX;
	for (int j = 0; j <= i; j++)
	{
		int temp_N = N, ret = 0;
		int k = 0;
		temp_N -= j * 5;
		ret += j;
		if (temp_N % 3 == 0)
		{
			ret += temp_N / 3;
			if (ret < min)
				min = ret;
		}
	}
	if (min == INT_MAX)
		printf("-1\n");
	else
		printf("%d\n", min);

	return (0);
}