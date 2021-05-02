// 가장 큰 동전을 제일 많이 쓰는 것이 최적
// 가장 가치가 큰 동전을 넘치기 직전까지 추가하고
// 그 다음에는 그 다음 가치의 동전을 비슷한 방식으로 추가

// 그러다 최종 목표 금액과 같아지면 그 때의 동전 갯수 출력

#include <stdio.h>


// int main(void)
// {
// 	int N;
// 	int K;
// 	scanf("%d %d", &N, &K);

// 	int arr[N];
// 	for (int i = 0; i < N; i++)
// 		scanf("%d", &arr[i]);

// 	int sum = 0;
// 	int coin = 0;
// 	for (int i = N - 1; i >= 0; i--)
// 		for (;sum + arr[i] <= K;)
// 		{
// 			sum += arr[i];
// 			coin++;
// 		}
// 	printf("%d\n", coin);

// 	return 0;
// }


int main(void)
{
	int N;
	int K;
	scanf("%d %d", &N, &K);

	int arr[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int sum = 0;
	int coin = 0;
	for (int i = N - 1; i >= 0 && sum != K; i--)
	{
		coin += (K - sum) / arr[i];
		sum += arr[i] * ((K - sum) / arr[i]);
	}

	printf("%d\n", coin);

	return 0;
}
