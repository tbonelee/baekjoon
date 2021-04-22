#include <stdio.h>

int N;
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		char str[81];
		scanf("%s", str);
		int sum = 0;
		int iter = 0;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == 'O')
			{
				iter++;
				sum += iter;
			}
			else
				iter = 0;
		}
		printf("%d\n", sum);
	}
}