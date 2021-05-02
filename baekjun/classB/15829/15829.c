#include <stdio.h>

#define m 1234567891
#define r 31

int main()
{
	int l; scanf("%d", &l);
	long long arr[51];
	arr[0] = 1;
	for (int i = 1; i < 51; i++)
	{
		arr[i] = (r * arr[i - 1]) % m;
		// printf("arr[%d] = %lld\n", i, arr[i]);
	}

	char str[51];
	scanf("%s", str);
	long long ret = 0;
	for (int i = 0; str[i]; i++)
	{
		ret += arr[i] * (str[i] - 'a' + 1);
		ret %= m;
	}
	printf("%lld\n", ret);
}