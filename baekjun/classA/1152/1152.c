#include <stdio.h>
int		is_in_charset(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}
int		count(char *str, char *charset)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (is_in_charset(str[i], charset) && str[i])
			i++;
		if (!is_in_charset(str[i], charset) && str[i])
			cnt++;
		while (!is_in_charset(str[i], charset) && str[i])
			i++;
		if (!str[i])
			break ;
	}
	return (cnt);
}

int main()
{
	char str[1000001];
	scanf("%[^\n]s", str);
	printf("%d\n", count(str, " "));
}