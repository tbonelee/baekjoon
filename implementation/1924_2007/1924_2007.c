#include <stdio.h>


int main()
{
	char *day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

	int x, y; scanf("%d %d", &x, &y);
	int month[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

	for (int i = 1; i < x; i++)
		y += month[i];
	printf("%s\n", day[y % 7]);
}