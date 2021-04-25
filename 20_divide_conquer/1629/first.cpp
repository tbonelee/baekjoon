#include <cstdio>
#include <vector>
int a, b, c;

int divide(int a, int b, int c);


int main(){
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", divide(a, b, c));
}

int divide(int a, int b, int c){
	if (b == 0){
		return 1;
	}
	else if (b % 2 == 0){
		long long modul = divide(a, b / 2, c);
		return modul * modul % c;
	}else{
		long long modul = divide(a, b - 1, c);
		return modul * a % c;
	}
}