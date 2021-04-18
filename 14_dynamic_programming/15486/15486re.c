// memo[i]에는 i번째 날 이전에 마친 상담들로 인한 최대 수입을 기록

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N; scanf("%d", &N);
	int *arr_t = (int *)calloc(N + 1, sizeof(int));
	int *arr_p = (int *)calloc(N + 1, sizeof(int));
	int *memo = (int *)calloc(N + 2, sizeof(int));
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &arr_t[i], &arr_p[i]);

	int max = 0;

	// N + 1번째까지 루프가 돌아야 퇴사일에 max가 갱신됨
	for (int i = 1; i <= N + 1; i++)
	{
		// i번째 날에 시작하는 상담을 마친 날의 다음 날을 payday로 놓음
		int payday = i + arr_t[i];
		// max는 i번째 날 전날에 끝나는 상담이 없는 경우 i번째 날까지 상담이 있음에도 불구하고 memo[i]에 0만 기록되어 있는 경우를 대비
		max = memo[i] > max ? memo[i] : max;
		// printf("i = %d, payday = %d\n", i, payday);
		// N + 1번째 날은 상담표 마지막날의 다음날로, 퇴사일과 동일
		// if문의 의미는, 오늘 시작하는 상담이 끝나고 난 다음 날이 퇴사일을 넘기지 않는다는 의미
		// 그 후 나오는 statement의 의미는
		// [ '현재까지 확인된 payday의 최대 수입(memo[payday])' 은 '오늘(i번째 날)의 최대 수입(max)'에 '오늘 시작하는 상담의 페이(arr_p[i])'를 더한 것과,
		//		'기존에(i번째 날 이전에) 시작해서 payday 전날 마친 상담'으로 인해 기록된 payday의 최대 수입(memo[payday])중 큰 값이 된다]는 의미.
		if (payday <= N + 1)
			memo[payday] = (max + arr_p[i] > memo[payday]) ? max + arr_p[i] : memo[payday];
	}


	printf("%d\n", max);




	free(arr_t);
	free(arr_p);
}