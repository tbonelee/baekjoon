#include <stdio.h>

int main()
{
	int arr[9];
	for (int i = 1; i <= 8; i++)
		scanf("%d", arr + i);
	int flagup = 1;
	int flagdown = 1;
	for (int i = 1; i <= 8; i++)
	{
		if (arr[i] != i)
			flagup = 0;
		if (arr[i] != 9 - i)
			flagdown = 0;
	}
	if (flagup == 1)
		printf("ascending\n");
	else if (flagdown == 1)
		printf("descending\n");
	else
		printf("mixed\n");


}