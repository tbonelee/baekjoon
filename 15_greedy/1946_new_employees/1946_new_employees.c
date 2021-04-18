//// 병합정렬의 시간복잡도 O(N)
//// find의 시간복잡도 O(N)
//// overall 시간복잡도 O(N)

#include <stdio.h>
#include <limits.h>

typedef struct s_rank t_rank;
struct s_rank
{
	int qual;
	int quan;
};
// t_rank g_temp1[100002];
// t_rank g_temp2[100002];

void	find(t_rank arr[], int N);

void	sort(t_rank arr[], int N);
// void	mergesort(t_rank arr[], int start, int end);
// void	merge(t_rank arr[], int start, int mid, int end);

int main()
{
	int T, N;
	t_rank arr[100001];

	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
	{
		scanf("%d", &N);
		for (int j = 1; j <= N; j++)
		{
			scanf("%d %d", &arr[j].qual, &arr[j].quan);
		}

		sort(arr, N);

		////////////////////병합정렬 테스트
		// printf("===test%d===\n", i);
		// for (int j = 1; j <= N; j++)
		// {
		// 	printf("qual = %d, quan = %d\n", arr[j].qual, arr[j].quan);
		// }
		//////////////////////

		find(arr, N);
		printf("\n");
	}
}




//// 우선 정성평가 순서대로 정렬한다
//// 그 후 맨 앞 사람부터 한 명씩 검사
//// temp_min에는 지금까지 체크한 사람 중 정량평가 순위가 가장 높은(숫자가 가장 작은) 사람의 정량평가 순위를 넣음
//// 어떤 사람 순서에서 그 사람의 정량평가 순위가 temp_min보다 크면(순위가 낮으면)
//// 그 앞에 있는 사람 중 누군가는 정성평가 순위도 그 사람보다 높고 (정성평가 순서대로 정렬했으므로)
//// 정량평가 순위도 높다는 것이므로
//// 해당 인원은 누군가에 의해 strictly dominated 된다.
//// 따라서 그런 사람이 존재하는 케이스에는 ret를 차감해서 신입사원 수를 줄인다.
void	find(t_rank arr[], int N)
{
	int ret = N, i = 1;
	int temp_min = INT_MAX;

	for (; i <= N; i++)
	{
		if (temp_min > arr[i].quan)
			temp_min = arr[i].quan;
		if (arr[i].quan > temp_min)
			ret--;
	}
	printf("%d", ret);
}


// 랭킹이 중복 없이 1부터 N까지 있기 때문에 이렇게 분류 가능
// 시간복잡도 O(N)
void	sort(t_rank arr[], int N)
{
	int idx;
	t_rank temp[100001];
	for (int i = 1; i <= N; i++)
	{
		idx = arr[i].qual;
		temp[idx] = arr[i];
	}
	for (int i = 1; i <= N; i++)
	{
		arr[i] = temp[i];
	}
}


// /////////////// 병합정렬
// void	mergesort(t_rank arr[], int start, int end)
// {
// 	if (start == end)
// 		return ;

// 	int mid = (start + end) / 2;

// 	mergesort(arr, start, mid);
// 	mergesort(arr, mid + 1, end);
// 	merge(arr, start, mid, end);
// }

// void	merge(t_rank arr[], int start, int mid, int end)
// {
// 	t_rank max; max.qual = INT_MAX; max.quan = INT_MAX;

// 	int i = start;
// 	for (; i <= mid; i++)
// 	{
// 		g_temp1[i] = arr[i];
// 	}
// 	g_temp1[i] = max;

// 	int j = mid + 1;
// 	for (; j <= end; j++)
// 	{
// 		g_temp2[j] = arr[j];
// 	}
// 	g_temp2[j] = max;

// 	int idx = start;
// 	for (i = start, j = mid + 1; (i != mid + 1 || j != end + 1); idx++)
// 	{
// 		if (g_temp1[i].qual <= g_temp2[j].qual)
// 		{
// 			arr[idx] = g_temp1[i++];
// 		}
// 		else
// 		{
// 			arr[idx] = g_temp2[j++];
// 		}
// 	}

// }