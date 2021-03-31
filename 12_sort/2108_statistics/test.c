#include <stdio.h>
#include <stdlib.h>

int num[500001] = { 0, };
int cnt[8001] = { 0, };

int compare(const void *a, const void *b) {		// qsort 오름차순 정렬 위한 함수
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

int maxFinder(int *arr, int size_arr) {		// 배열에서 최댓값 찾는 함수
	int maxV = arr[0];
	for (int i = 0; i < size_arr; i++)
		if (maxV < arr[i])
			maxV = arr[i];

	return maxV;
}

int main() {
	int N, sum = 0, flags = 0;
	int min = 4000, max = -4000;
	int mode = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		sum += num[i];			// 산술평균을 구하기 위해 모든 값의 합을 구함

		if (min > num[i])		// 범위를 구하기 위해 최대, 최솟값을 구함
			min = num[i];
		if (max < num[i])
			max = num[i];

		cnt[num[i] + 4000]++;	// 최빈값을 찾기 위해 각 숫자가 몇 번 나왔는지 세기 위한 변수
	}

	for (int i = 0; i < 8001; i++)				// 최빈값 구하는 부분
		if (maxFinder(cnt, 8001) == cnt[i])
			flags++;

	for (int i = 0; i < 8001; i++) {
		if (flags == 1) {
			if (maxFinder(cnt, 8001) == cnt[i]) {
				mode = i - 4000;
				break;
			}
		}
		else {
			if (maxFinder(cnt, 8001) == cnt[i]) {
				if (flags == 0) {
					mode = i - 4000;
					break;
				}
				else
					flags = 0;
			}
		}
	}

	qsort(num, N, sizeof(int), compare);	// 중앙값을 구하기 위해 qsort 정렬을 사용함

	printf("%.0f\n", (double)sum / N);
	printf("%d\n", num[(N + 1) / 2 - 1]);
	printf("%d\n", mode);
	printf("%d\n", max - min);

	return 0;
}