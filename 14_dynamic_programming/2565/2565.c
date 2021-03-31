// 결국 LIS를 찾는 문제


#include <stdio.h>


int tab[1005];
int arr[1005];

int main()
{
	int N;
	scanf("%d", &N);


	int max = 0;

	int final_max = 0;
	for (int i = 1; i <= N; i++)
	{
		int where;
		scanf("%d", &where);

		if (where > max)
			max = where;

		scanf("%d", &arr[where]);
	}


	for (int i = 1; i <= max; i++)
	{
		int temp_max = 0;

		if (arr[i] != 0)
		{
			for (int j = 1; j < i; j++)
				if (arr[j] != 0 && arr[j] < arr[i] && tab[j] > temp_max)
					temp_max = tab[j];
			tab[i] = temp_max + 1;
			if (tab[i] > final_max)
				final_max = tab[i];

		}
	}

	printf("%d\n", N - final_max);

	return (0);
}