// 1부터 N번째 와인 잔이 존재할 때 각 와인잔에 대해 마시거나 안 마시거나 두 가지 선택이 가능
// 맨 왼쪽부터 와인을 마실지 안 마실지 선택하면서 오른쪽으로 넘어간다고 하자.
// 인접한 세 잔의 와인을 모두 마실 수 없으므로
// N번째 와인을 마실 수 있는지의 여부는
// N-1번째 와인을 마셨는지와 N-2번째 와인을 마셨는지에 달려있다.

// 동적계획법을 적용하기 위해 int memo[N + 1][4]을 선언하여 사용할 것이다.
// memo[i][j]에서 i는 몇번째 와인 순서인지를 의미한다.
// j는 2진수로 나타내었을 때 직전 와인을 마셨는지 여부와 현재 자리에서 와인을 마셨는지 여부를 나타낸다.
// 예를 들어 j가 10(2)(== 2)라면 직전의 와인은 마셨지만 현 위치의 와인은 마시지 않았음을 의미
// memo[i][j]에 있는 값은 해당 i와 j에 해당하는 경우의 수 중에서
// 가장 와인을 많이 마시게 된 sum이 저장되도록 한다.

// input[N + 1]이 선언되고
// input[i]에는 i번째 와인의 양이 기록된다.

// 점화식을 작성해보면 다음과 같다.
// memo[i][00(2)] = max{memo[i - 1][00(2)], memo[i - 1][10(2)]}
// memo[i][01(2)] = max{memo[i - 1][00(2)], memo[i - 1][10(2)]} + input[i]
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

int max_of_four(int a, int b, int c, int d)
{
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;
	return (max);
}

int find(int N, int input[])
{
	if (N == 1)
		return (input[1]);
	else if (N == 2)
		return (input[1] + input[2]);

	int memo[N + 1][4];

	// memo[1][0b10]과 memo[1][0b11]은 실제로 가능한 경우의 수가 아니지만 계산의 편의를 위해 추가
	memo[1][0b00] = 0;
	memo[1][0b01] = input[1];
	memo[1][0b10] = 0;
	memo[1][0b11] = 0;


	for (int i = 2; i <= N; i++)
	{
		memo[i][0b00] = max(memo[i - 1][0b00], memo[i - 1][0b10]);
		memo[i][0b01] = max(memo[i - 1][0b00], memo[i - 1][0b10]) + input[i];
		memo[i][0b10] = max(memo[i - 1][0b01], memo[i - 1][0b11]);
		memo[i][0b11] = memo[i - 1][0b01] + input[i];

		// printf("memo[%d][%d] = %d\n", i, 0b00, memo[i][0b00]);
		// printf("memo[%d][%d] = %d\n", i, 0b01, memo[i][0b01]);
		// printf("memo[%d][%d] = %d\n", i, 0b10, memo[i][0b10]);
		// printf("memo[%d][%d] = %d\n", i, 0b11, memo[i][0b11]);
		// printf("\n");
	}

	// printf("1 = %d\n 2 = %d\n 3 = %d\n 4 = %d\n", memo[N][0b00], memo[N][0b01], memo[N][0b10], memo[N][0b11]);
	return (max_of_four(memo[N][0b00], memo[N][0b01], memo[N][0b10], memo[N][0b11]));
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