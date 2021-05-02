#include <cstdio>

int main(){
	printf("100 10000000\n");
	for (int i = 1; i <= 10000000; i++)
		printf("10000000 ");
	printf("\n");
	for (int i = 1; i <= 10000000; i++)
		printf("100 ");
	printf("\n");
}