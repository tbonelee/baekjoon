#include <stdio.h>

int main()
{
	int a, b; scanf("%d %d", &a, &b);
	int r = 1;
	int aa = a, bb = b;
	while (r)
	{
		r = aa % bb;
		aa = bb;
		bb = r;
	}
	printf("%d ", aa);
	printf("%d\n", (a / aa) * (b / aa) *aa);

}