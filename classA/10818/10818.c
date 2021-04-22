#include <stdio.h>
#include <limits.h>

int main()
{
	int n; scanf("%d", &n);
	int max = INT_MIN, min = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		int temp; scanf("%d", &temp);
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
	}
	printf("%d %d\n", min, max);
}