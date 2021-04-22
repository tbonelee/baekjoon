#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);
	char str[101]; scanf("%s", str);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += str[i] - '0';
	}
	printf("%d\n", sum);
}