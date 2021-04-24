// 최단경로 -> BFS
// 벽을 만날 때마다 경우의 수가 두 배로 늘어나는 거라고 처음에 생각했으나
// 해당 위치에서 벽을 깨고 난 후의 최단 거리만 기록하면 되는 것이고, BFS의 특성상 방문하는 순간 최단 거리를 기록할 수 있으므로 경우의 수가 지수 함수꼴로 증가하지 않는다.
// 따라서 BFS 적용 가능

// cf) 처음에는 DFS로 시도해보았으나 최단 거리의 문제 특성상 DFS 적용시 경우의 수가 급격하게 증가 -> 시간초과

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int ivec[4] = {0, 0, -1, 1};
int jvec[4] = {-1, 1, 0, 0};

void BFS(int n, int m, vector<vector<int> > map, vector<vector<pair<int, int> > > &memo);

int main(){
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int> > map(n + 1, vector<int>(m + 1, 0));

	// pair<int, int> map[1001][1001];
	char str[1005];
	for (int i = 1; i <= n; i++){
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++){
			map[i][j]= str[j] - '0';
		}
	}
	// printf("test\n");
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= m; j++){
	// 		printf("%d", map[i][j].first);
	// 	}
	// 	printf("\n");
	// }
	// int min = INT_MAX;
	vector<vector<pair<int, int> > > memo(n + 1, vector<pair<int, int> >(m + 1, {0, 0}));
	BFS(n, m, map, memo);
	// if (min == INT_MAX)
	// 	min = -1;
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= m; j++){
	// 		printf("%5d ", memo[i][j].first);
	// 	}
	// 	printf("\n");
	// }
	// printf("========\n");
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= m; j++){
	// 		printf("%5d ", memo[i][j].second);
	// 	}
	// 	printf("\n");
	// }
	if (memo[n][m].first == 0 && memo[n][m].second != 0)
		printf("%d\n", memo[n][m].second);
	else if (memo[n][m].first != 0 && memo[n][m].second == 0)
		printf("%d\n", memo[n][m].first);
	else if (memo[n][m].first == 0 && memo[n][m].second == 0)
		printf("-1\n");
}

void BFS(int n, int m, vector<vector<int> > map, vector<vector<pair<int, int> > > &memo){
	queue<pair<pair<int, int>, int> > Q;
	Q.push({{1,1}, 1});
	memo[1][1].second = 1;
	int itemp, jtemp;
	int ipos, jpos;
	int joker;
	// pair<pair<int, int>, int> temp;
	while (!Q.empty()){
		ipos = Q.front().first.first;
		jpos = Q.front().first.second;
		joker = Q.front().second;
		Q.pop();
		if (ipos == n && jpos == m)
			return ;
		for (int k = 0; k < 4; k++){
			itemp = ipos + ivec[k];
			jtemp = jpos + jvec[k];
			// printf("itemp = %d, jtemp = %d\n",itemp, jtemp);
			if (itemp >= 1 && itemp <= n && jtemp >= 1 && jtemp <= m){
				if (map[itemp][jtemp] == 0){
					if (joker == 1 && memo[itemp][jtemp].second == 0){
						memo[itemp][jtemp].second = memo[ipos][jpos].second + 1;
						Q.push({{itemp, jtemp}, joker});
					}
					// printf("case1 itemp = %d, jtemp = %d\n", itemp, jtemp);
					if (joker == 0 && memo[itemp][jtemp].first == 0){
						memo[itemp][jtemp].first = memo[ipos][jpos].first + 1;
						Q.push({{itemp, jtemp}, joker});
					}
				}
				if (map[itemp][jtemp] == 1 && joker == 1 && memo[itemp][jtemp].first == 0){
					// printf("case2 itemp = %d, jtemp = %d\n", itemp, jtemp);
					memo[itemp][jtemp].first = memo[ipos][jpos].second + 1;
					Q.push({{itemp, jtemp}, 0});
				}
			}
		}
	}
}