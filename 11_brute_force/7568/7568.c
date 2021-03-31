#include <stdio.h>
#include <stdlib.h>

void	findrank(int num, int *weight, int *height, int *rank)
{
	for (int i = 0, cnt; i < num; i++)
	{
		cnt = 1;
		for (int j = 0; j < num; j++)
			if (j != i
			&& weight[i] < weight[j] && height[i] < height[j])
				cnt++;
		rank[i] = cnt;
	}
}

int main()
{
	int num;

	scanf("%d", &num);

	int *weight, *height, *rank;
	weight = (int *)malloc(sizeof(int) * num);
	height = (int *)malloc(sizeof(int) * num);
	rank = (int *)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d %d", &weight[i], &height[i]);

	findrank(num, weight, height, rank);

	for (int i = 0; i < num - 1; i++)
		printf("%d ", rank[i]);
	printf("%d", rank[num - 1]);

	free(weight);
	free(height);
	free(rank);
	return 0;
}