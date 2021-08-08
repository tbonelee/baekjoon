#include <iostream>
#include <map>

using namespace std;

int N, M;

map<string, string> m1;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		string tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		m1.insert(pair<string, string>(tmp1, tmp2));

	}
	for (int i = 0; i < M; i++){
		string tmp;
		cin >> tmp;
		cout << m1.find(tmp)->second << "\n";
	}
}