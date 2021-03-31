// tab[N + 1][K + 1]의 배열을 선언
// tab[i][j]는 첫번째 물건부터 i번째 물건까지 하나씩 넣을지말지 선택하면서 올라왔을 때,
// 선택한 물건들로 인해 배낭의 무게가 j까지 되었을 때 최대의 무게라 할 수 있다

// 점화식은 다음과 같다
// tab[i][j] = max {tab[i - 1][j], tab[i - 1][j - i번째 물건 무게] + i번째 물건 효용}

// tab[i][j]가 -1로 채워져 있는 것은 해당 순번의 물건 탐색 단계에서 해당 무게를 맞출 수 없음을 의미한다.
// 만약 tab[i - 1][j]와 tab[i - 1][j - i번재 물건 무게] 둘 모두 -1이면
// i번째 물건을 선택하든 안 하든, j의 무게는 맞출 수 없으므로 tab[i][j] 또한 -1이 된다.

// 시간복잡도 : O(N * M)

#include <stdio.h>

int g_max_result;
typedef struct s_info{
	int weight;
	int utility;
} t_info;

int find_sub(int i, int j, int K, int arr_weight[], int arr_utility[], int tab[][K + 1])
{
	int temp1 = tab[i - 1][j];
	int temp2 = tab[i - 1][j - arr_weight[i]];

// 불필요하게 tab값을 여러 번 확인하지 않게 하기 위해 중첩된 if 문을
// j - arr_weight[i]가 0 미만인 경우는 해당 물건을 추가하여 해당 무게를 달성할 수 없으므로
// 해당 물건을 추가하는 경우는 고려하지 않아야 함(temp2 확인할 필요 없음)
if (j - arr_weight[i] >= 0)
{
	if (temp1 == -1)
	{
		if (temp2 == -1)
			return (-1);
		else
			return (temp2 + arr_utility[i]);
	}
	else
	{
		if (temp2 == -1)
			return (temp1);
		else
			return (temp1 > temp2 + arr_utility[i] ? temp1 : temp2 + arr_utility[i]);
	}
}
else
{
	if (temp1 == -1)
		return (-1);
	else
		return (temp1);
}
}

void find(int N, int K, int arr_weight[], int arr_utility[], int tab[][K + 1])
{
	//	아무 물건을 선택하지 않아도 0의 무게는 맞출 수 있으므로 tab[0][0]은 0으로 놓을 수 있음
	tab[0][0] = 0;

	for (int j = 1; j<= K; j++)
	{
		tab[0][j] = -1;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= K; j++)
		{
			tab[i][j] = find_sub(i, j, K, arr_weight, arr_utility, tab);
			if (tab[i][j] > g_max_result)
				g_max_result = tab[i][j];
		}
}

int main()
{
	int N;
	scanf("%d", &N);
	int K;
	scanf("%d", &K);

	int arr_weight[N + 1];
	int arr_utility[N + 1];
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr_weight[i]);
		scanf("%d", &arr_utility[i]);
	}

	int tab[N + 1][K + 1];

	find(N, K, arr_weight, arr_utility, tab);

	printf("%d\n", g_max_result);

	return 0;
}