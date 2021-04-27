
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct compare{
	bool operator()(pair<int, int> &a, pair<int, int> &b){
		return a.first < b.first;
	}
};

vector<int> solution(vector<int> prices) {
    vector<int> answer;
	int leng = prices.size();
	answer.resize(leng);
	priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
	for (int i = 0; i < leng; i++){
		if (!pq.empty() && pq.top().first > prices[i]){
			while (!pq.empty() && pq.top().first > prices[i]){
				int idx = pq.top().second;
				int time = i - idx;
				answer[idx] = time;
				pq.pop();
			}
		}
		pq.push(make_pair(prices[i], i));
	}
	while (!pq.empty()){
		int idx = pq.top().second;
		int time = leng - 1 - idx;
		answer[idx] = time;
		pq.pop();
	}

    return answer;
}