#include <stdio.h>
#include <string.h>


int main()
{
	int alpha[26];
	memset(alpha, -1, sizeof(alpha));
	char str[101]; scanf("%s", str);
	for (int i = 0; str[i]; i++)
	{
		if (alpha[str[i] - 'a'] == -1)
			alpha[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
}