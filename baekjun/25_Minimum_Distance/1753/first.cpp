// 다익스트라

#include <queue>
#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int V, E, K;

struct compare{
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.second > b.second;
	}
};

void add_graph(vector<vector<pair<int, int> > > &adj_lists, int u, int v, int w){
	adj_lists[u].push_back({v, w});
}

int main(){
	// cin.tie(NULL);
	// ios::sync_with_stdio(false);
	cin >> V >> E >> K;
	int u, v, w;
	vector<vector<pair<int, int> > > adj_lists(V + 1);
	for (int i = 1; i <= E; i++){
		cin >> u >> v >> w;
		add_graph(adj_lists, u, v, w);
	}
	vector<int> dist(V + 1, INT_MAX);
	vector<bool> visited(V + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;

	pq.push({K, 0});
	dist[K] = 0;
	while (!pq.empty()){


		// cout << "here\n";
		int visit_pos = pq.top().first;
		int visit_dist = pq.top().second;
		visited[pq.top().first] = true;
		pq.pop();
		for (int i = 0; i < adj_lists[visit_pos].size(); i++){
			// cout << "hrer\n";
			int temp_pos = adj_lists[visit_pos][i].first;
			dist[temp_pos] = min(dist[temp_pos], visit_dist + adj_lists[visit_pos][i].second);
			pq.push({temp_pos, dist[temp_pos]});
		}
		while (!pq.empty() && visited[pq.top().first] == true)
			pq.pop();
	}
	for (int i = 1; i <= V; i++){
		if (dist[i] == INT_MAX)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}