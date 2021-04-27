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
#include <cstdio>
#include <iostream>
int main(){
	// priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
	// pq.push(make_pair(1,2));
	// pq.push(make_pair(2,4));
	// pq.push(make_pair(3,6));
	// pq.push(make_pair(4,2));
	// pq.push(make_pair(5,3));
	// while (!pq.empty()){
	// 	cout << pq.top().first << ", " << pq.top().second << endl;
	// 	pq.pop();
	// }
	vector<int> prices = {3, 2, 1};
	vector<int> ans = solution(prices);
	for (auto& i : ans){
		cout << i << endl;
	}
}