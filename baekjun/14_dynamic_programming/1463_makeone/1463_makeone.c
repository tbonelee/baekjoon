// 숫자 N이 주어졌을 때 1에서 N으로 가는 가장 짧은 길을 찾는 문제로 뒤집어서 생각할 수 있다.
// 1번 연산은 3을 곱하는 연산
// 2번 연산은 2를 곱하는 연산
// 3번 연산은 1을 더하는 연산

// memo[i]에는 숫자 i가 되기 위해 필요한 최소의 연산 횟수가 기록된다.

// i가 2로 나누어 떨어지고, 3으로 나누어 떨어지지 않는 수인 경우
// memo[i] = max{memo[i / 2], memo[i - 1]} + 1

// i가 3으로 나누어 떨어지고, 2로 나누어 떨어지지 않는 수인 경우
// memo[i] = max{memo[i / 3], memo[i - 1]} + 1

// i가 2, 3으로 나누어 떨어지지 않는 수인 경우
// memo[i] = memo[i - 1] + 1

// i가 6으로 나누어 떨어지는 경우

#include <stdio.h>

int memo[1000001];

int min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int find(int N)
{
	if (N == 1)
		return (0);

	int memo[N + 1];
	int modulo2;
	int modulo3;

	memo[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		modulo2 = i % 2, modulo3 = i % 3;
		if (modulo2 == 0 && modulo3 != 0)
			memo[i] = min(memo[i / 2], memo[i - 1]) + 1;
		else if (modulo2 != 0 && modulo3 == 0)
			memo[i] = min(memo[i / 3], memo[i - 1]) + 1;
		else if (modulo2 != 0 && modulo3 != 0)
			memo[i] = memo[i - 1] + 1;
		else
			memo[i] = min(memo[i / 3], min(memo[i / 2], memo[i - 1])) + 1;
	}
	return (memo[N]);
}

int main()
{
	int N;
	scanf("%d", &N);

	printf("%d\n", find(N));

	return 0;
}