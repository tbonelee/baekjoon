// 참조 : https://jdselectron.tistory.com/61

// 최단경로 -> BFS
// 벽을 만날 때마다 경우의 수가 두 배로 늘어나는 거라고 처음에 생각했으나
// 해당 위치에서 벽을 깨고 난 후의 최단 거리만 기록하면 되는 것이고, BFS의 특성상 방문하는 순간 최단 거리를 기록할 수 있으므로 경우의 수가 지수 함수꼴로 증가하지 않는다.
// 따라서 BFS 적용 가능

// cf) 처음에는 DFS로 시도해보았으나 최단 거리의 문제 특성상 DFS 적용시 경우의 수가 급격하게 증가 -> 시간초과

// scanf여러 번 하는 것이 느리다 해서 char str[1001]로 한 줄씩 받아서 처리하려 했더니 메모리 초과 나옴.
// 그래서 동적 배열한 후 free로 해제


#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
#include <cstdbool>
#include <cstdlib>

using namespace std;

int ivec[4] = {0, 0, -1, 1};
int jvec[4] = {-1, 1, 0, 0};
int memo[1001][1001][2] = {0,};
bool map[1001][1001] = {0, };
int n, m;

void BFS(void);

int main(){
	scanf("%d %d", &n, &m);

	char *str = (char *)calloc(m + 2, 1);
	for (int i = 1; i <= n; i++){
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++){
			map[i][j]= str[j] - '0';
		}
	}
	free(str);

	BFS();

	if (memo[n][m][0] == 0 && memo[n][m][1] != 0)
		printf("%d\n", memo[n][m][1]);
	else if (memo[n][m][0] != 0 && memo[n][m][1] == 0)
		printf("%d\n", memo[n][m][0]);
	else if (memo[n][m][0] == 0 && memo[n][m][1] == 0)
		printf("-1\n");
	else
		printf("%d\n", memo[n][m][0] < memo[n][m][1] ? memo[n][m][0] : memo[n][m][1]);
}

void BFS(void){
	queue<pair<pair<int, int>, int> > Q;
	Q.push({{1,1}, 1});
	memo[1][1][1] = 1;
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
				if (map[itemp][jtemp] == 0 && memo[itemp][jtemp][joker] == 0){
					memo[itemp][jtemp][joker] = memo[ipos][jpos][joker] + 1;
					Q.push({{itemp, jtemp}, joker});
				}
				if (map[itemp][jtemp] == 1 && joker == 1 && memo[itemp][jtemp][0] == 0){
					// printf("case2 itemp = %d, jtemp = %d\n", itemp, jtemp);
					memo[itemp][jtemp][0] = memo[ipos][jpos][1] + 1;
					Q.push({{itemp, jtemp}, joker - 1});
				}
			}
		}
	}
}