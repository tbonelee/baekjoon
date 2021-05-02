#include <stdio.h>

int a,b,v;

int main()
{
	scanf("%d %d %d", &a, &b, &v);
	int temp_v = v - a;
	int day;
	if (temp_v % (a - b) == 0)
	{
		day = temp_v / (a - b) + 1;
	}
	else
	{
		day = temp_v / (a - b) + 2;
	}
	printf("%d\n", day);
}