#include <stdio.h>
#include <string.h>

int main()
{
	char str[1000001];
	scanf("%s", str);
	int memo[26];
	memset(memo, 0, sizeof(memo));
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			memo[str[i] - 'a']++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			memo[str[i] - 'A']++;
	}
	int max = 0;
	int maxidx;
	int flag = 0;
	for (int i = 0; i < 26; i++)
	{
		if (memo[i] > max)
		{
			flag = 0;
			max = memo[i];
			maxidx = i;
		}
		else if (memo[i] == max)
		{
			// printf("here");
			flag = 1;
		}
	}
	// for (int i = 0; i < 26; i++)
	// {
	// 	printf("i = %d, %d\n", i, memo[i]);
	// }
	if (flag == 1)
		printf("?\n");
	else
		printf("%c\n", 'A' + maxidx);
}