#include <stdio.h>


int main()
{
	int N;
	int temp;

	scanf("%d", &N);

	int counting[10001] = {0};


	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		counting[temp]++;
	}
	for (int i = 1; i <= 10000; i++)
		for (int j = 0; j < counting[i]; j++)
			printf("%d\n", i);

	return 0;
}