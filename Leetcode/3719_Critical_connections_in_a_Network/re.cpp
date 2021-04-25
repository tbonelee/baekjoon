// first.cpp를 이해한 후 복기를 해봄.
// 인접배열을 벡터의 고정 크기 배열(사이즈 n)로 되어 있는 것을 이중 배열로 바꿔보았다(vla는 컴파일러에 따라 지원하지 않는 것으로 알고 있어서)
// 그렇게 했더니 인접배열 참조에서 속도가 많이 느려서 타임아웃 발생.
// 주소에 기반하여 요소에 접근하더라도 벡터는 고정 크기 배열보다 느릴 수 있는 것 같다

// 범위 기반 for문 사용시에도 참조를 사용하는 것이 불필요한 값 복사를 방지하여 속도가 조금 빨라지는 것을 확인할 수 있었다(leetcode 제출 통해 확인)
// cf) https://boycoding.tistory.com/210

#include <cstdio>

class Solution {
public:

	vector<vector<int> > ans;

	vector<int> tin, lowest;

	vector<bool> visited;

	int time = 0;


	void dfs(int pos, int parent, vector<vector<int> > adj){
		tin[pos] = lowest[pos] = time++;
        // printf("tin[%d] = %d, lowest = %d\n", pos, tin[pos], lowest[pos]);
		visited[pos] = true;
		// 범위 기반 for문
		for (int &iter : adj[pos]){
			if (iter == parent)
				continue;
			if (visited[iter] == true)
				lowest[pos] = min(lowest[pos], tin[iter]);
			else{
				dfs(iter, pos, adj);
				lowest[pos] = min(lowest[pos], lowest[iter]);
                // printf(" tin[%d] = %d, lowest[%d] = %d\n", pos, tin[pos], iter, lowest[iter]);
				if (tin[pos] < lowest[iter]){
					vector<int> temp;
					temp.push_back(pos);
					temp.push_back(iter);
					ans.push_back(temp);
				}
			}
		}
	}

    vector<vector<int>> criticalConnections(int n, vector<vector<int> >& connections) {
		vector<vector<int> > adj(n);
		for (int i = 0; i < connections.size(); i++){
			// printf("conn[%d][0] = %d, [1] = %d\n", i, connections[i][0], connections[i][1]);
			int u = connections[i][0];
			int v = connections[i][1];

			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		// for (int i = 0; i < n; i++){
		// 	for (int j = 0; j < adj[i].size(); j++){
		// 		std::cout << adj[i][j] << ", ";
		// 	}
		// 	std::cout << endl;
		// }
		tin.assign(n, 0);
		lowest.assign(n, 0);
		visited.assign(n, false);
		dfs(0, -1, adj);
		return ans;
	}
};