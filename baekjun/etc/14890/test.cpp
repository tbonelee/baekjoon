#include <iostream>

using namespace std;

int main(){
	for (int i = 0; i < 10; i++){
		cout << i << "\n";
		if (i == 2){
			printf(" i = 2\n");
			i++;
			printf("after= %d\n", i);
			continue ;
		}
	}
}