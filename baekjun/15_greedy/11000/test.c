#include <stdio.h>

int main()
{
	printf("200000\n");
	for (int i = 1; i <= 200000; i++)
		printf("%d %d\n", i, 200001);
}