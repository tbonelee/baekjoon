#include <stdio.h>

#define MAX 2147483647
// #define abs(num) ((num) >= 0 ? (num) : -1 * (num))

int team1_check[30];
int MIN;
int N;
int arr[30][30];


int abs(int num)
{
	return (num >= 0 ? num : -num);
}

void renew_min()
{
	int score1 = 0;
	int score2 = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (team1_check[i] == 1
			&& team1_check[j] == 1)
				score1 += arr[i][j];
			if (team1_check[i] == 0
			&& team1_check[j] == 0)
				score2 += arr[i][j];
		}
	if (abs(score1 - score2) < MIN)
		MIN = abs(score1 - score2);
}

void recursive(int previous_value, int idx)
{
	int i;
	if (idx == N / 2)
	{
		renew_min();
		return ;
	}

	for (i = previous_value + 1; i < N; i++)
	{

		team1_check[i] = 1;
		recursive(i, idx + 1);
		team1_check[i] = 0;
	}


}

int main()
{
	MIN = MAX;


	scanf("%d", &N);


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < N; i++)
	{
		team1_check[i] = 1;
		recursive(i, 1);
		team1_check[i] = 0;
	}

	printf("%d\n", MIN);
	return 0;
}