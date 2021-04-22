#include <stdio.h>

int modulo[42];

int main()
{
	int temp;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &temp);
		modulo[temp %= 42]++;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++)
	{
		if (modulo[i] != 0)
			cnt++;
	}
	printf("%d\n", cnt);


}