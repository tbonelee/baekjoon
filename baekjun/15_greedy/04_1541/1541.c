#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[51];
	scanf("%s", str);

	char num[6];
	int i_num = 0;
	int result = 0;
	int flag = 1;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num[i_num++] = str[i];
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			i_num = 0;

			result += flag * atoi(num);

			if (str[i] == '-')
				flag = -1;
			memset(num, 0, 6);
		}
	}
	result += flag * atoi(num);
	printf("%d\n", result);

	return 0;
}