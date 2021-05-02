#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str1[4], str2[4]; scanf("%s %s", str1, str2);
	char temp = str1[0];
	str1[0] = str1[2];
	str1[2] = temp;
	temp = str2[0];
	str2[0] = str2[2];
	str2[2] = temp;

	int num1 = atoi(str1), num2 = atoi(str2);
	printf("%d\n", num1 > num2 ? num1 : num2);
}