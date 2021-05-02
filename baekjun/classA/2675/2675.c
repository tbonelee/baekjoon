	#include <stdio.h>

	int main()
	{
		int T; scanf("%d", &T);
		for (int i = 1; i <= T;i++)
		{
			int R; scanf("%d", &R);
			char str[21]; scanf("%s", str);
			for (int i = 0; str[i]; i++)
				for (int j = 1; j <= R; j++)
					printf("%c", str[i]);
			printf("\n");
		}
	}