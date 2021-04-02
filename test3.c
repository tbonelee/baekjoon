
#include <stdio.h>

void	DFS(int n, int m, int arr[], int index)
{
	int j;

	if (m == index)
	{
		for (j = 0; j < m - 1; j++)
		{
			// printf("%d ", arr[j]);
		}
		// printf("%d", arr[j]);
		// printf("\n");
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		arr[index] = i + 1;
		DFS(n, m, arr, index + 1);
	}
}
#include <time.h>
int	main()
{
	int n, m;

	scanf("%d %d", &n, &m);

clock_t start[100];
clock_t end[100];
for (int i = 0; i < 100 ; i++)
{
	start[i] = clock();
	int arr[m];
	DFS(n, m, arr, 0);


	end[i] = clock();
}
double mean = 0;
for (int i = 0; i < 100; i++)
{
	mean += (double)(end[i] - start[i]);
}
mean /= 100;
	// printf("Time: %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
	printf("Time: %lf\n", mean / CLOCKS_PER_SEC);
}