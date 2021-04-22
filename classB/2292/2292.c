#include <stdio.h>

int main()
{
	int ret = 0;
	int n; scanf("%d", &n);
	int num = 1;
	for (int i = 0; ; i++)
	{
		num += 6 * i;
		ret++;
		if (n <= num)
			break;
	}
	printf("%d\n", ret);
}