

// LIS 문제와 비슷하게 풀어보려고 함

// 여기서는 상승 추세인지 하락 추세인지에 따라 다른 배열을 도입


#include <stdio.h>


int arr[1005];
int tab_asc[1005];
int tab_des[1005];

int main()
{
	int N;
	scanf("%d", &N);


	int final_max = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);

		int temp_max_asc = 0;
		int temp_max_des = 0;

		for (int j = 1; j < i; j++)
		{
			// 불필요한 조건문 비교를 방지하기 위해 중첩된 if문 사용
			if (arr[j] < arr[i])
			{
				if (tab_asc[j] > temp_max_asc)
					temp_max_asc = tab_asc[j];
			}
			else if (arr[j] > arr[i])
			{

				int sub;
				if ((sub = (tab_asc[j] > tab_des[j] ? tab_asc[j] : tab_des[j])) > temp_max_des)
					temp_max_des = sub;
				// if (tab_asc[j] > tab_des[j] && tab_asc[j] > temp_max_des)
				// 	temp_max_des = tab_asc[j];
				// else if (tab_asc[j] <= tab_des[j] && tab_des[j] > temp_max_des)
				// 	temp_max_des = tab_des[j];
			}
		}
		tab_asc[i] = temp_max_asc + 1;
		tab_des[i] = temp_max_des + 1;

		if (tab_asc[i] > final_max)
			final_max = tab_asc[i];
		if (tab_des[i] > final_max)
			final_max = tab_des[i];
	}

	printf("%d\n", final_max);

	return (0);
}