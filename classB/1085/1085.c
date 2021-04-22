#include <stdio.h>

int x,y,w,h;

int main()
{
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int min1, min2;
	min1 = x < w - x ? x : w - x;
	min2 = y < h - y ? y : h - y;
	printf("%d\n", min1 < min2 ? min1 : min2);
}