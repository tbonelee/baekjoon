#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int> > minheap;
	priority_queue<int> maxheap;
	// int qsize = 0;
	// cout << maxheap.size();
	for (int i = 0; i < n; i++){
		int temp; cin >> temp;
		if (maxheap.size() <= minheap.size()){

			if (maxheap.empty() || temp <= minheap.top())
				maxheap.push(temp);
			// else if (minheap.empty())
			else{
				// if (minheap.empty())
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(temp);
			}
		}else{
			if (temp >= maxheap.top())// || minheap.empty())
				minheap.push(temp);
			else{
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(temp);
			}
		}
		cout << maxheap.top() << "\n";

	}
}