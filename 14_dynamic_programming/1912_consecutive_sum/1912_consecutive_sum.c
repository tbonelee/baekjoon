// 해당 숫자를 sum에 선택할 때 얻을 수 있는 최댓값은
// 직전 숫자에서 얻은 최댓값에 현재값을 더하거나
// 직전 숫자를 무시하고 자신부터 시작해서 새로운 연속합을 만드는 것이다.

// arr[]가 인풋 숫자들의 배열이고
// tab[]이 왼쪽부터 오른쪽으로 가면서 각 인풋 숫자들을 선택해서 만들 수 있는 최댓값의 연속합이라 하면
// 점화식은 다음과 같다.

// tab[i] = max{tab[i - 1] + arr[i], arr[i]}

#include <stdio.h>
#include <limits.h>

extern inline int ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	int N;

	scanf("%d", &N);

	int arr[N + 1];
	int tab[N + 1];
	int result = INT_MIN;

	tab[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);

		if (tab[i - 1] > 0)
			tab[i] = tab[i - 1] + arr[i];
		else
			tab[i] = arr[i];

		if (tab[i] > result)
			result = tab[i];

		// tab[i] = ft_max(tab[i - 1] + arr[i], )
	}

	printf("%d\n", result);

	return (0);


}