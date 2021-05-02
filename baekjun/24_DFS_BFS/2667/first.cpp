#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ivec[4] = {0, 0, 1, -1};
int jvec[4] = {1, -1, 0, 0};

void dfs(vector<vector<int> > &map, int i, int j, int &buildings){
	map[i][j] = 0;
	buildings++;
	for (int k = 0; k < 4; k++){
		int itemp = i + ivec[k];
		int jtemp = j + jvec[k];
		if (0 <= itemp && itemp < n && 0 <= jtemp && jtemp < n && map[itemp][jtemp] == 1){
			// cout << "df(" << i << ", " << j << ") ";
			dfs(map, itemp, jtemp, buildings);
		}
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<vector<int> > map(n, vector<int>(n));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			char ch = cin.get();
			if (ch == '\n')
				ch = cin.get();
			map[i][j] = ch - '0';
		}
	}

	int cnt = 0;
	vector<int> building_lists;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 1){
				int buildings = 0;
				dfs(map, i, j, buildings);
				cnt++;
				building_lists.push_back(buildings);
			}
	cout << cnt << "\n";
	sort(building_lists.begin(), building_lists.end());
	for (auto &elem : building_lists)
		cout << elem << "\n";
	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < n; j++){
	// 		cout << map[i][j];
	// 	}
	// 	cout << "\n";
	// }
}