// 거리 문제 -> BFS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <utility>

using namespace std;

int t, board_size;
int vec[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

int main(){
	cin >> t;
	for (int i = 0; i < t; i++){
		scanf("%d", &board_size);
		vector<vector<int> > board(board_size, vector<int>(board_size, -1));
		int ipos, jpos; scanf("%d %d", &ipos, &jpos);
		int idest, jdest; scanf("%d %d", &idest, &jdest);
		queue<pair<array<int, 2>, int> >q;
		pair<array<int, 2>, int> temp;
		temp.first[0] = ipos; temp.first[1] = jpos;
		board[ipos][jpos] = 0;
		temp.second = board[ipos][jpos];
		q.push(temp);
		while(!q.empty()){
			int ipop = q.front().first[0];
			int jpop = q.front().first[1];
			int dist = q.front().second;
			q.pop();
			if (ipop == idest && jpop == jdest){
				printf("%d\n", dist);
				break ;
			}
			for (int k = 0; k < 8; k++){
				int itemp = ipop + vec[k][0];
				int jtemp = jpop + vec[k][1];
				if (itemp >= 0 && itemp <= board_size - 1 && jtemp >= 0 && jtemp <= board_size - 1){
					if (board[itemp][jtemp] == -1){
						board[itemp][jtemp] = dist + 1;
						temp.first[0] = itemp; temp.first[1] = jtemp;
						temp.second = board[itemp][jtemp];
						q.push(temp);
					}
				}
			}
		}
	}
}