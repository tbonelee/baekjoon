#include <stdio.h>
#include <limits.h>

int n, m, b;

int main()
{
	int arr[500][500];
	scanf("%d %d %d", &n, &m, &b);
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] < min)
				min = arr[i][j];
			if (arr[i][j] > max)
				max = arr[i][j];
		}
	int mintime = INT_MAX;
	int height_at_min;
	for (int height = min; height <= max; height++)
	{
		// printf("(before)temp = %d\n", temp_b);
		int time = 0;
		int temp_b = b;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] < height)
				{
					temp_b -= height - arr[i][j];
					time += height - arr[i][j];
				}
				else
				{
					temp_b += arr[i][j] - height;
					time += 2 * (arr[i][j] - height);
				}
			}
		if (temp_b >= 0)
		{
			if (time <= mintime)
			{
				mintime = time;
				height_at_min = height;
			}
		}
		// printf("(after)temp = %d\n", temp_b);
	}
	printf("%d %d\n", mintime, height_at_min);

}