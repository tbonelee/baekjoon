// 출처 : https://youtu.be/Vw85B-nb-2Q

class Solution {
public:
	// to store the answer
	vector<vector<int>> ans;

	// timer to store the time at dfs traversal
	int timer = 0;

	// visited array;
	vector<bool> visited;

	// tin stores the entry time for any node
	// low stores the minimum time
	vector<int> tin, low;

	void dfs(int v, int par, vector<int> adj[]){
		visited[v] = true;

		// initialize tin[v] and low[v] with current time
		tin[v] = low[v] = timer++;
		for (int u : adj[v]){
			if (u == par)
				continue;
			if (visited[u])
				low[v] = min(low[v], tin[u]);
			else{
				dfs(u, v, adj);
				low[v] = min(low[v], low[u]);

				// check for back edge
				if (low[u] > tin[v]){
					// BRIDGE {v --> u}
					vector<int> temp;
					temp.push_back(v);
					temp.push_back(u);
					ans.push_back(temp);
				}
			}
		}
	}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		ans.clear();

		// adjacency list
		vector<int> adj[n];

		visited.assign(n, false);
		tin.assign(n, -1);
		low.assign(n, -1);

		for (int i = 0; i < connections.size(); i++){
			int u = connections[i][0];
			int v = connections[i][1];

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		// find out all the bridges
		dfs(1, -1, adj);

		return ans;
	}
};