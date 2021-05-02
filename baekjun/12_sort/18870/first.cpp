#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool a_is_less_in_first(pair<int, int> a, pair<int, int> b){
	return (a.first < b.first);
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<pair<int, int> > v;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		pair<int, int> temp;
		cin >> temp.first;
		temp.second = i;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), a_is_less_in_first);
	// for (int i = 0; i < n; i++)
	// 	cout << v[i].first << " ";
	// cout << "\n";
	// for (int i = 0; i < n; i++)
	// 	cout << v[i].second << " ";
	// cout << "\n";
	vector<int> ret(n);
	// int re = 0;
	ret[v[0].second] = 0;
	int cnt = 0;
	for (int i = 1; i < n; i++){
		if (v[i].first != v[i - 1].first){
			ret[v[i].second] = ret[v[i - 1].second] + 1;
		}else{
			ret[v[i].second] = ret[v[i - 1].second];
		}
	}
	for (auto &elem : ret)
		cout << elem << " ";

	cout << "\n";
}