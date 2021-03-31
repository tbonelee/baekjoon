#include <stdio.h>
#include <stdlib.h>

int g_max;

void	findmax(int number_of_cards, int dest_num, int *arr)
{

	for (int i = 0; i < number_of_cards - 2; i++)
	{
		for (int j = i + 1; j < number_of_cards - 1; j++)
		{
			for (int k = j + 1; k < number_of_cards; k++)
			{
				if (arr[i] + arr[j] + arr[k] > g_max && arr[i] + arr[j] + arr[k] <= dest_num)
					g_max = arr[i] + arr[j] + arr[k];
			}
		}
	}
}

int main()
{
	int number_of_cards;
	int dest_num;

	scanf("%d %d", &number_of_cards, &dest_num);

	int *arr = (int *)malloc(sizeof(int) * number_of_cards);
	for (int i = 0; i < number_of_cards; i++)
		scanf("%d", &arr[i]);
	findmax(number_of_cards, dest_num, arr);
	free(arr);
	printf("%d", g_max);
	return 0;
}