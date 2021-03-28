// 규칙을 찾지 못해 결국 풀이를 참조..

// 점화식은 다음과 같습니다
// 첫번째 문자열을 a[], 두번째 문자열을 b[]라고 했을 때
// LCS(a[i], b[j])는 세 가지 경우로 나눌 수 있습니다.
// 1) i 또는 j가 0인 경우
//		(여기서 문자열은 1번째부터 시작한다고 가정해서 0인 경우는 문자를 가리키지 않는 것으로 함)
// 2) a[i]와 b[j]의 문자가 동일한 경우
// 3) a[i]와 b[j]의 문자가 다른 경우

// 1)의 경우에는 공통의 문자가 있을 수 없으므로 LCS == 0이 됩니다.
// 2)의 경우, 두 문자열 모두 직전 문자에 있을 때의 LCS에 새로 겹치는 부분을 더하게 되므로
//		LCS(a[i], b[j])  = LCS(a[i - 1], b[j - 1]) + 1이 됩니다.
// 3)의 경우, 마지막 문자는 겹치지 않으므로 둘 중 하나의 마지막 문자는 무시할 수 있습니다.
//		(만약 둘 중 하나가 LCS가 더 커지게 하는 요인이 되더라도 둘이 동시에 LCS를 증가시킬 수는 없으므로)
// 따라서 LCS(a[i], b[j]) == max{LCS(a[i - 1], b[j]), LCS(a[i], b[j - 1])}이 됩니다.

// 이러한 점화식 구조를 통해 문제를 풀어보겠습니다.

#include <stdio.h>

extern inline int max(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	char arr1[1005];
	char arr2[1005];



	for (int i = 1; arr1[i - 1] != '\n'; i++)
		scanf("%c", &arr1[i]);

	for (int i = 1; arr2[i - 1] != '\n'; i++)
		scanf("%c", &arr2[i]);




	// for (int i = 1; arr1[i - 1] != '\n'; i++)
	// 	printf("%c", arr1[i]);
	// printf("\n");
	// for (int i = 1; arr2[i - 1] != '\n'; i++)
	// 	printf("%c", arr2[i]);



	int tab[1005][1005];
	int maxnum = 0;

	for (int i = 0; arr1[i] != '\n'; i++)
	{
		for (int j = 0; arr2[j] != '\n'; j++)
		{
			if (!i || !j)
				tab[i][j] = 0;
			else if (arr1[i] == arr2[j])
				tab[i][j] = tab[i - 1][j - 1] + 1;
			else
				tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);

			if (tab[i][j] > maxnum)
				maxnum = tab[i][j];

			// printf("%2d", tab[i][j]);
		}
		// printf("\n");
	}
	printf("%d\n", maxnum);

	return (0);
}