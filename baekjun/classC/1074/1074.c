#include <stdio.h>

int n;
int r,c;

int main()
{
	scanf("%d %d %d", &n, &r, &c);
	int twopow[16];
	twopow[0] = 1;
	for (int i = 1; i <= 15; i++)
		twopow[i] = twopow[i - 1] * 2;
	int num = 0;
	for (int i = n; i >= 1; i--)
	{
		int t = (twopow[i] - 1) / 2;
		if (r <= t && c <= t)
			;
		else if (r <= t && c > t)
		{
			num += 1 * twopow[i - 1] * twopow[i - 1];
			c -= t + 1;
		}
		else if (r > t && c <= t)
		{
			num += 2 * twopow[i - 1] * twopow[i - 1];
			r -= t + 1;
		}
		else
		{
			num += 3 * twopow[i - 1] * twopow[i - 1];
			r -= t + 1;
			c -= t + 1;
		}
	}
	printf("%d\n", num);
}