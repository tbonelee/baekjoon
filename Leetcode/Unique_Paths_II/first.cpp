#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
	void dfs(vector<vector<int> > &map, int ipos, int jpos, int idest, int jdest, vector<vector<int> > &dp){
		if (ipos == 0 && jpos == 0){
			if (map[ipos][jpos] == 0)
				dp[0][0] = 1;
		}
		if (ipos + 1 <= idest && map[ipos + 1][jpos] == 0)
			dp[ipos + 1][jpos] += dp[ipos][jpos];
		if (jpos + 1 <= jdest && map[ipos][jpos + 1] == 0)
			dp[ipos][jpos + 1] += dp[ipos][jpos];
	}

    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
		// int ret = 0;
		int idest = obstacleGrid.size() - 1;
		int jdest = obstacleGrid[0].size() - 1;
		vector<vector<int> > dp(idest + 1, vector<int>(jdest + 1, 0));
		// if (obstacleGrid[0][0] == 0)
		for (int i = 0; i <= idest; i++){
			for (int j = 0; j <= jdest; j++)
				dfs(obstacleGrid, i, j, idest, jdest, dp);
		}

		// dfs(obstacleGrid, 0, 0, idest, jdest, dp);
		for (int i = 0; i <= idest; i++){
			for (int j = 0; j <= jdest; j++){
				cout << dp[i][j] << " ";
			}
			cout << "\n";
		}
		return dp[idest][jdest];
    }
};