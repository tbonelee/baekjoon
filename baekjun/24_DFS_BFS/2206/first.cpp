#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int ivec[4] = {0, 0, -1, 1};
int jvec[4] = {-1, 1, 0, 0};

void DFS(int ipos, int jpos, int dist, int n, int m, int joker, int &min, vector<vector<pair<int, int> > > map);

int main(){
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<pair<int, int> > > map(n + 1, vector<pair<int, int> >(m + 1, {0, 0}));

	// pair<int, int> map[1001][1001];
	char str[1001];
	for (int i = 1; i <= n; i++){
		scanf("%s", str);
		for (int j = 0; j < m; j++){
			map[i][j + 1].first = str[j] - '0';
		}
	}
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= m; j++){
	// 		printf("%d", map[i][j].first);
	// 	}
	// 	printf("\n");
	// }
	int min = INT_MAX;
	map[1][1].second = 1;
	DFS(1, 1, 1, n, m, 1, min, map);
	if (min == INT_MAX)
		min = -1;
	printf("%d\n", min);
}

void DFS(int ipos, int jpos, int dist, int n, int m, int joker, int &min, vector<vector<pair<int, int> > > map){
	if (ipos == n && jpos == m){
		if (dist < min)
			min = dist;
		return ;
	}
	int itemp, jtemp;
	for (int k = 0; k < 4; k++){
		itemp = ipos + ivec[k];
		jtemp = jpos + jvec[k];
		// printf("itemp = %d, jtemp = %d\n",itemp, jtemp);
		if (itemp >= 1 && itemp <= n && jtemp >= 1 && jtemp <= m){
			if (map[itemp][jtemp].first == 0 && map[itemp][jtemp].second == 0){
				// printf("case1 itemp = %d, jtemp = %d\n", itemp, jtemp);
				map[itemp][jtemp].second = 1;
				DFS(itemp, jtemp, dist + 1, n, m, joker, min, map);
				map[itemp][jtemp].second = 0;
			}
			if (map[itemp][jtemp].first == 1 && joker == 1){
				// printf("case2 itemp = %d, jtemp = %d\n", itemp, jtemp);
				DFS(itemp, jtemp, dist + 1, n, m, joker - 1, min, map);
			}
		}
	}
}