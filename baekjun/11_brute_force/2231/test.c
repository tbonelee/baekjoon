#include <stdio.h>
#include <math.h>

int main() {
	int N, result = 0;
	int sum = 0;

	// scanf("%d", &N);
	N = 1000000;
	for (int i = 1; i < N; i++) {
		sum = 0;
		for (int j = 5; j >= 0; j--)
			sum += (i / (int)pow(10, j) % 10);
		sum += i;

		if (sum == N) {
			result = i;
			break;
		}
	}
    printf("%d\n", result);

	return 0;
}