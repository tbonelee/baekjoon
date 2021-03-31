// 가장 큰 동전을 제일 많이 쓰는 것이 최적
// 가장 가치가 큰 동전을 넘치기 직전까지 추가하고
// 그 다음에는 그 다음 가치의 동전을 비슷한 방식으로 추가

// 그러다 최종 목표 금액과 같아지면 그 때의 동전 갯수 출력

#include <stdio.h>

void onlymerge(int start, int end, int arr[])
{
	
}

void mergesort(int start, int end, int arr[])
{
	int middle = (start + end) / 2;

	if (start == end)
		return ;

	mergesort(start, middle - 1, arr);
	mergesort(middle, end, arr);

	onlymerge(start, end, arr);
}

int main(void)
{
	int N;
	int K;
	scanf("%d %d", &N, &K);

	int arr[N];



	return 0;
}