#include <stdio.h>

#define MAX 2147483647

int MIN;
int sum = 0;


// idx의 위치에서 i의 색을 칠하려 할 때, 직전 단계의 비용 중 i와 다른 색들 중 최솟값을 반환
int min(int color_idx, int sum[][3], int idx)
{
	int min = MAX;

	for (int j = 0; j < 3; j++)
		if (j != color_idx && sum[idx - 1][j] < min)
			min = sum[idx - 1][j];

	return (min);
}


// 맨 뒤에서부터 함수를 콜하는 형식
// 첫번째 파라미터가 현재 체크하는 위치를 의미(한 단계 재귀로 내려갈 때 1을 차감한 값이 입력됨)
// arr는 입력받은 비용 구조가 기록되어있음
// sum[i][j]에는 j에 해당하는 색(0,1,2가 R,G,B)을 i번째 칸에 칠하려 할 때 최소 비용이 입력되어 있음
// (동적 계획에서 메모의 역할)
//
void find_min(int idx, int N, int arr[][3], int sum[][3], int color_idx)
{
	if (idx == 0)
		return ;

	for (int j = 0; j < 3; j++) // j는 직전 칸에 칠할 색을 의미
	{
		if (color_idx != j) // 인접한 칸에 같은 색을 칠하는 경우는 고려하지 않음
		{
				// 직전 칸 결과가 계산되지 않은 경우에만 함수를 콜한다
				// && idx가 1일 때는 직전 칸 결과가 당연히 0이므로 이 때는 함수를 콜하지 않도록
				// 조건에 고려
			if (sum[idx - 1][j] == 0 && idx != 1)
			{
				find_min(idx - 1, N, arr, sum, j);
			}
		}
	}
	// 현재 위치에서 특정 색(i)을 칠하려 할 때
	// 직전 단계에서 자신과 다른 색(j)을 칠할 때의 최소비용들이 구해지게 한 다음
	// 현재 i색 칠할 때의 비용과 직전 단계 두 가지 색 칠할 때 비용 중 최소 비용을 구해서 합한다.
	// 계산되지 않은 경우에만 계산
	if (sum[idx][color_idx] == 0)
		sum[idx][color_idx] = min(color_idx, sum, idx) + arr[idx][color_idx];

}






int main()
{
	MIN = MAX;

	int N;
	scanf("%d", &N);

	// N + 1로 선언한 것은 인덱스와 실제 순번의 괴리를 제거하기 위함.
	int arr[N + 1][3];
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	int sum[N + 1][3];
	 // 0번째 인덱스까지 0이 되게 하면
	 // find_min의 재귀함수가 1번 집 위치에 있을 때
	 // 직전 비용을 더하는 과정에서 0을 더하게 돼서 1번 이후 집 위치에서 칠하는 경우와
	 // 함수 구조를 다르게 고려할 필요가 없다.
	for (int i = 0; i <= N; i++)
		for (int j = 0; j < 3; j++)
			sum[i][j] = 0;

	find_min(N, N, arr, sum, 0);
	find_min(N, N, arr, sum, 1);
	find_min(N, N, arr, sum, 2);


	if (sum[N][0] < sum[N][1])
		MIN = sum[N][0];
	else
		MIN = sum[N][1];
	if (sum[N][2] < MIN)
		MIN = sum[N][2];



	printf("%d\n", MIN);
	return 0;
}