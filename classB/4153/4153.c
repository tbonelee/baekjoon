#include <stdio.h>

int arr[3];

int main()
{
	while (1)
	{
		scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			return 0;
		int max;
		if (arr[0] > arr[1])
			max = 0;
		else
			max = 1;
		if (arr[2] > arr[max])
			max = 2;
		int hypotenuse = 0;
		int remain = 0;
		for (int i = 0; i < 3; i++)
		{
			if (i == max)
				hypotenuse += arr[i] * arr[i];
			else
				remain += arr[i] * arr[i];
		}
		if (remain == hypotenuse)
			printf("right\n");
		else
			printf("wrong\n");
	}
}