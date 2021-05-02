#include <stdio.h>

int triple_six(int n, int cnt)
{
	if (cnt == 3)
		return -1;
	if (n == 0)
		return -2;
	if ((cnt == 0 || cnt == 1 || cnt == 2) && n % 10 == 6)
		n = triple_six(n / 10, cnt + 1);
	else
		n = triple_six(n / 10, 0);

	return n;
}

int main()
{
	int n;
	int ret;
	scanf("%d", &n);

	for (int i = 0, cnt = 0;; i++)
	{
		if (triple_six(i, 0) == -1)
			cnt++;
		if (cnt == n)
		{
			ret = i;
			break;
		}
	}

	printf("%d", ret);
}