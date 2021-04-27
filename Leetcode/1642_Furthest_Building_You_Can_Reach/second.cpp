// O(n * log L)
// n = 빌딩 수
// L = 사다리수

#include <queue>
#include <vector>
#include <algorithm>

using std::priority_queue;
using std::vector;
// using std::sort;
using std::min;
using std::greater;
using std::swap;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
		int leng = heights.size();
		priority_queue<int, vector<int>, greater<int> > pq;
		int i;
		for (i = 0; i + 1 < leng && pq.size() < ladders; i++){
			int jumps = heights[i + 1] - heights[i];
			if (jumps > 0)
				pq.push(jumps);
		}
		for (; i + 1 < leng; i++){
			int jumps = heights[i + 1] - heights[i];
			if (jumps > 0){
				if (!pq.empty() && pq.top() < jumps){
					bricks -= pq.top();
					pq.pop();
					pq.push(jumps);
				}else{
					bricks -= jumps;
				}
			}
			if (bricks < 0){
				return i;
			}
		}
		return i;
	}
};