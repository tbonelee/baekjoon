#include <stdio.h>
#include <string.h>

char arr[6];
int main()
{
	while(1)
	{
		scanf("%s", arr);
		if (arr[0] == '0')
			break;
		int flag = 1;
		for (int i = 0; i < (int)strlen(arr) / 2; i++)
		{
			if (arr[i] != arr[strlen(arr) - i - 1])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			printf("no\n");
		else
			printf("yes\n");

	}
}