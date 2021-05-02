#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cop{
	bool operator()(const int a, const int b){
	if (abs(a) == abs(b))
		return a > b;
	return (abs(a) > abs(b));
	}
};

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<int, vector<int>, cop> pq;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		int temp; cin >> temp;
		if (temp == 0){
			if (pq.empty())
				cout << "0\n";
			else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}else
			pq.push(temp);
	}
}