#include <vector>
#include <utility>
#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pair<int , int> > lists;
	for (int i = 0; i < 3; i++){
		int x, y; cin >> x >> y;
		// cout << x << " "<< y << "\n";
		lists.push_back(make_pair(x, y));

	}
	pair<int, int> same1, same2, another;
	if (lists[0].first == lists[1].first){
		same1 = lists[0];
		same2 = lists[1];
		another = lists[2];
	}else if (lists[0].first == lists[2].first){
		same1 = lists[0];
		same2 = lists[2];
		another = lists[1];
	}else if (lists[1].first == lists[2].first){
		same1 = lists[1];
		same2 = lists[2];
		another = lists[0];
	}
	// for (int i = 0; i < 3; i++){
	// 	cout << lists[i].first << " " << lists[i].second << "\n";
	// }
	// cout << same1.first << " " << same1.second << "\n";/
	int x = another.first;
	int y;
	if (same1.second != another.second)
		y = same1.second;
	else
		y = same2.second;
	cout << x << " " << y << "\n";
}