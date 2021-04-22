#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);
	int flag = 0;
	if (n % 4 == 0)
	{
		if (n % 400 == 0)
			flag = 1;
		else if (n % 100 != 0)
			flag = 1;

	}
	printf("%d\n", flag);
}