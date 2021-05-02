	// 끝나는 시간 기준으로 오름차순 정렬
	// 가장 먼저 끝나는 회의는 선택
	// 그 다음 선택하는 회의는 직전에 선택한 회의의 종료 시간보다 같거나 늦게 회의가 시작하고,
	// 		가장 일찍 끝나는 회의
	// 끝나는 시간 기준으로 이미 정렬했기 때문에
	// 배열의 첫 번째 회의부터 올라가면서 따져보면 된다.

	// 끝나는 시간이 같은 경우에는 시작시간 기준으로 오름차순 정렬이 한 번 더 필요하다
	// 2 7 8 8 8이 입력된 경우와 2 8 8 8 8이 입력된 경우를 생각해보면
	// 전자는 처음에 (7, 8)이 선택되고 (8, 8)이 선택되지만
	// 후자는 (8, 8)을 한 번 선택하면 시작시간이 8보다 빠른 (7, 8)을 선택할 수 없다.

	// 따라서 이를 막기 위해 qsort에서 비교할 때 end가 같으면 start끼리도 비교하도록 해두었다.




#include <stdio.h>
#include <stdlib.h>

typedef struct s_input{
	int start;
	int end;
}	t_input;

int compare(const void *a, const void *b)
{

	if (((t_input *)a)->end > ((t_input *)b)->end)
		return (1);
	else if (((t_input *)a)->end == ((t_input *)b)->end)
	{
		if (((t_input *)a)->start > ((t_input *)b)->start)
			return (1);
		else if (((t_input *)a)->start == ((t_input *)b)->start)
			return (0);
		else
			return (-1);
	}
	else
		return (-1);

}


int find(int N, t_input info[])
{
	int ret = 0;
	int temp_overall_end = 0;

	qsort(info, N + 1, sizeof(t_input), &compare);

	for (int i = 1; i <= N; i++)
		if (info[i].start >= temp_overall_end)
		{
			ret++;
			temp_overall_end = info[i].end;

		}

	return (ret);
}

int main()
{
	int N;
	scanf("%d", &N);

	t_input info[N + 1];
	info[0].start = 0; info[0].end = 0;
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &info[i].start, &info[i].end);

	printf("%d\n", find(N, info));

	return 0;
}