#include <stdio.h>

int main()
{
	int hh, mm; scanf("%d %d", &hh, &mm);

	if (mm < 45)
	{
		mm += 60;

		if (hh == 0)
			hh += 24;
		hh--;
	}
	mm -= 45;
	printf("%d %d\n", hh, mm);

}