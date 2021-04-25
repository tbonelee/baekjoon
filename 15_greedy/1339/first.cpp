#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;
using std::greater;

int n;

// struct compare{
// 	bool operator()(int a, int b){
// 		return a. < b.second;
// 	}
// }

int main(){
	vector<char *> str;
	vector<int> alphas;
	alphas.assign(26, 0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		char *temp = new char[12];
		scanf("%s", temp);
		int leng = strlen(temp);
		int tens = 1;
		for (int j = leng - 1; j >= 0; j--){
			alphas[temp[j] - 'A'] += tens;
			tens *= 10;
		}
		// printf("%s\n", temp);
		// temp[strlen(temp) - 1] = 0;
		// str.push_back(temp);
	}
	// for (int i = 0; i < 26; i++)
	// {
	// 	printf("i = %d, alphas[i] = %d\n", i, alphas[i]);
	// }
	priority_queue<int, vector<int> > pq;
	for (int i = 0; i < alphas.size(); i++){
		if (alphas[i])
			pq.push(alphas[i]);
	}
	int ret = 0;
	for (int i = 0; i < 10 && !pq.empty(); i++){
		ret += pq.top() * (9 - i);
		// printf("pq.top() = %d\n", pq.top());
		pq.pop();
	}
	printf("%d\n", ret);
}