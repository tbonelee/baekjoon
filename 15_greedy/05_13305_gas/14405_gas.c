// i번째 주유소 가격을 k라 놓자.
// i + n(n >= 1)번째 주유소 가격이 k보다 낮지 않는 한 n을 1씩 계속 증가시킨다.
// 그러다 더 싼 주유소를 발견하면 그 전 도시까지의 기름은 i번째 주유소에서 주유한다.

#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);

	int distance[N - 1];
	int price[N];
	for (int i = 0; i < N - 1; i++)
		scanf("%d", distance + i);
	for (int i = 0; i < N; i++)
		scanf("%d", price + i);

	long long result = 0;
	int start = 0;
	int i;
	for (i = 0; i < N - 1;)
	{

		if (price[i] < price[start])
		{
			for (int j = start; j < i; j++)
				result += (long long)price[start] * (long long)distance[j];
			start = i;
		}

	}
	for (int j = start; j < i; j++)
		result += (long long)price[start] * (long long)distance[j];
	printf("%lld\n", result);



}