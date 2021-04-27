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
		int *num_of_jumps = new int[heights.size()];
		num_of_jumps[0] = 0;
		for (int i = 1; i < heights.size(); i++){
			if (heights[i] > heights[i - 1])
				num_of_jumps[i] = heights[i] - heights[i - 1];
			else
				num_of_jumps[i] = 0;
		}
		priority_queue<int, vector<int> > pq;
		vector<int> lists;
		int sum = 0;
		int used_bricks = 0;
		int used_ladders = 0;
		for (int i = 0; i < heights.size(); i++){
			int min_of_tops;
			if (lists.size() >= ladders && ladders)
				min_of_tops = lists[ladders - 1];
			if (num_of_jumps[i]){
				lists.push_back(num_of_jumps[i]);
				used_ladders = min(ladders, (int)lists.size());
				if (lists.size() > ladders){
					sort(lists.begin(), lists.end(), greater<int>());
					if (ladders && min_of_tops < lists[ladders - 1]){
						used_bricks += min_of_tops;
					}else{
						used_bricks += num_of_jumps[i];
					}
					lists.pop_back();
				}
			}
			if (used_bricks > bricks){
				delete []num_of_jumps;
				return i - 1;
			}
		}
		return heights.size() - 1;
    }
};