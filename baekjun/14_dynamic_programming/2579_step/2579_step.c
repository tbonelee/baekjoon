
// 1부터 N번째 계단이 존재할 때 각 계단을 밟거나 안 밟는 문제로 변환해서 생각할 수 있다.
// 각 계단을 밟을 수 있는지 여부(could)는 직전 두 칸을 모두 밟은 경우가 아니어야 하므로 직전 두 칸의 경로에 의존하며,
// 각 계단을 밟아야 하는지 여부(must)는 계단 연속 두 칸을 밟지 않고 넘어갈 수 없으므로 마찬가지로 직전 두 칸의 경로에 의존한다.



// 동적계획법을 적용하기 위해 int memo[N + 1][4]을 선언하여 사용할 것이다.
// memo[i][j]에서 i는 몇번째 계단 순서인지를 의미한다.
// j는 2진수로 나타내었을 때 직전 계단을 밟았는지 여부와 현재 자리에서 계단을 밟았는지 여부를 나타낸다.
// 예를 들어 j가 10(2)(== 2)라면 직전의 계단은 밟았지만 현 위치의 계단은 밟지 않았음을 의미
// memo[i][j]에 있는 값은 해당 i와 j에 해당하는 경우의 수 중에서
// 가장 높은 점수의 sum이 저장되도록 한다.

// input[N + 1]이 선언되고
// input[i]에는 i번째 계단의 숫자가 기록된다.


// 점화식을 작성해보면 다음과 같다.
// memo[i][01(2)] = memo[i - 1][10(2)] + input[i]
// memo[i][10(2)] = max{memo[i - 1][01(2)], memo[i - 1][11(2)]}
// memo[i][11(2)] = memo[i - 1][01(2)] + input[i]

// cf) C에서 2진수를 받기 위해서는 숫자 앞에 0b 또는 0B를 붙여주면 된다.

#include <stdio.h>

int max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int find(int N, int input[])
{
	if (N == 1)
		return (input[1]);
	else if (N == 2)
		return (input[1] + input[2]);

	int memo[N + 1][4];

	// memo[1][0b10]과 memo[1][0b11]은 실제로 가능한 경우의 수가 아니지만 계산의 편의를 위해 추가
	memo[1][0b01] = input[1];
	memo[1][0b10] = 0;
	memo[1][0b11] = 0;


	for (int i = 2; i <= N; i++)
	{
		memo[i][0b01] = memo[i - 1][0b10] + input[i];
		memo[i][0b10] = max(memo[i - 1][0b01], memo[i - 1][0b11]);
		memo[i][0b11] = memo[i - 1][0b01] + input[i];

	}

	return (max(memo[N][0b01], memo[N][0b11]));
}

int main()
{
	int N;
	scanf("%d", &N);

	int input[N + 1];
	for (int i = 1; i <= N; i++)
		scanf("%d", &input[i]);

	printf("%d\n", find(N, input));

	return 0;
}