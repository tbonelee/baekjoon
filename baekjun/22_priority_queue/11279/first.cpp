#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<int> pq;
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