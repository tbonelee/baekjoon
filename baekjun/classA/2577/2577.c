#include <stdio.h>
#include <string.h>

int main()
{
	int a, b, c; scanf("%d\n%d\n%d", &a, &b, &c);
	int num[10];
	memset(num, 0, sizeof(num));
	int mult = a * b * c;

	while (mult > 0)
	{
		num[mult % 10]++;
		mult /= 10;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", num[i]);

}