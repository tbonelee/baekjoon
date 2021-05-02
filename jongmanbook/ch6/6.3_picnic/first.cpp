#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int t, n, m;

void find(vector<vector<bool> > friends, vector<bool> &lists, int &ret, int left);

int main(){
	cin >> t;
	vector<int> result;
	for (int i = 0; i < t; i++){
		cin >> n >> m;

		vector<vector<bool> > friends(n, vector<bool>(n, false));
		for (int j = 0;  j < m; j++){
			int a, b;
			cin >> a >> b;
			friends[a][b] = true;
			friends[b][a] = true;
		}
		// cout << endl;
		// for (int i = 0; i < n; i++){
		// 	for (int j = 0; j < n; j++){
		// 		cout << friends[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int ret = 0;
		vector<bool> lists(n, true);
		// cout << endl;
		// for (int i = 0; i < n; i++)
		// 	cout << lists[i] << " ";
		// cout << endl;

		find(friends, lists, ret, n);
		// cout << ret << endl;

		// printf("%d", ret);
		result.push_back(ret);
	}
	for (auto &elem : result)
		cout << elem << endl;

}

void find(vector<vector<bool> > friends, vector<bool> &lists, int &ret, int left){
	if (left == 0){
		ret++;
		return ;
	}
	for (int i = 0; i < n - 1; i++){
		if (lists[i] == true){
			for (int j = i + 1; j < n; j++){
				if (lists[j] == true && friends[i][j] == true){
					// for (int idx = 0; idx <= i ; idx++)
					// 	lists[idx] = false;
					lists[i] = lists[j] = false;
					find(friends, lists, ret, left - 2);
					// for (int idx = 0; idx <= i ; idx++)
					// 	lists[idx] = true;
					lists[i] = lists[j] = true;
				}
			}
			break ;
		}
	}
}