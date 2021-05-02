// #include <vector>

// using namespace std;

// class Solution {
// public:
// 	int find(vector<int>& nums, int start, int end, int target){
// 		if (start > end)
// 			return -1;
// 		int mid = (start + end) / 2;
// 		if (nums[mid] == target)
// 			return mid;
// 		else if (nums[mid] > target)
// 			return find(nums, start, mid - 1, target);
// 		else
// 			return find(nums, mid + 1, end, target);
// 	}

// 	vector<int> searchRange(vector<int>& nums, int target) {
// 		int whereat = find(nums, 0, nums.size() - 1, target);
// 		int start, end;
// 		start = end = whereat;
// 		int endidx = nums.size() - 1;
// 		vector<int> ret(2, -1);
// 		if (whereat != -1){
// 			for (;;){
// 				if (!((start - 1 >= 0 && nums[start - 1] == target) || (end + 1 <= endidx && nums[end + 1] == target)))
// 					break ;
// 				if (start - 1 >= 0 && nums[start - 1] == target)
// 					start--;
// 				if (end + 1 <= endidx && nums[end + 1] == target)
// 					end++;
// 			}
// 			ret[0] = start;
// 			ret[1] = end;
// 		}
// 		return ret;
// 	}
// };


// #include <vector>

// using namespace std;

// class Solution {
// public:
// 	int findlower(vector<int>& nums, int start, int end, int target){
// 		// int ans = -1;
// 		int temp;
// 		if (start > end)
// 			return -1;
// 		int mid = (start + end) / 2;
// 		if (nums[mid] == target)
// 			return ((temp = findlower(nums, start, mid - 1, target)) != -1 && temp < mid ? temp : mid);
// 		else if (nums[mid] > target)
// 			return findlower(nums, start, mid - 1, target);
// 		else
// 			return findlower(nums, mid + 1, end, target);
// 	}
// 	int findupper(vector<int>& nums, int start, int end, int target){
// 		int temp;
// 		if (start > end)
// 			return -1;
// 		int mid = (start + end) / 2;
// 		if (nums[mid] == target)
// 			return ((temp = findupper(nums, mid + 1, end, target)) != -1 && temp > mid ? temp : mid);
// 		else if (nums[mid] > target)
// 			return findupper(nums, start, mid - 1, target);
// 		else
// 			return findupper(nums, mid + 1, end, target);
// 	}

// 	vector<int> searchRange(vector<int>& nums, int target) {
// 		vector<int> ret;
// 		ret.push_back(findlower(nums, 0, nums.size() - 1, target));
// 		ret.push_back(findupper(nums, 0, nums.size() - 1, target));
// 		return ret;
// 	}
// };



#include <vector>

using namespace std;

class Solution {
public:
	int findlower(vector<int>& nums, int start, int end, int target){
		int ans = -1;
		// int temp;
		while (start <= end){
			int mid = (start + end) / 2;
			if (nums[mid] == target){
				ans = mid;
				end = mid - 1;
			}else if (nums[mid] > target)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return ans;
	}
	int findupper(vector<int>& nums, int start, int end, int target){
		int ans = -1;
		// int temp;
		while (start <= end){
			int mid = (start + end) / 2;
			if (nums[mid] == target){
				ans = mid;
				start = mid + 1;
			}else if (nums[mid] > target)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return ans;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		ret.push_back(findlower(nums, 0, nums.size() - 1, target));
		ret.push_back(findupper(nums, 0, nums.size() - 1, target));
		return ret;
	}
};


// class Solution {
// public:
// 	int findlower(vector<int>& nums, int start, int end, int target){
// 		int ans = -1;
// 		// int temp;
// 		while (start <= end){
// 			int mid = (start + end) / 2;
// 			if (nums[mid] == target){
// 				ans = mid;
// 				end = mid - 1;
//                 continue;
// 			}
//             if (nums[mid] > target){
// 				end = mid - 1;
//                 continue;
//             }
// 			if (nums[mid] < target){
//                 start = mid + 1;
//                 continue;
//             }
// 		}
// 		return ans;
// 	}
// 	int findupper(vector<int>& nums, int start, int end, int target){
// 		int ans = -1;
// 		// int temp;
// 		while (start <= end){
// 			int mid = (start + end) / 2;
// 			if (nums[mid] == target){
// 				ans = mid;
// 				start = mid + 1;
//                 continue;
// 			}
//             if (nums[mid] > target){
// 				end = mid - 1;
//                 continue;
//             }
// 			if (nums[mid] < target){
//                 start = mid + 1;
//                 continue;
//             }
// 		}
// 		return ans;
// 	}

// 	vector<int> searchRange(vector<int>& nums, int target) {
// 		// vector<int> ret;
// 		// ret.push_back(findlower(nums, 0, nums.size() - 1, target));
// 		// ret.push_back(findupper(nums, 0, nums.size() - 1, target));
// 		// return ret;
//         // return {findlower(nums,0, nums.size() - 1, target), findupper(nums, 0, nums.size() - 1, target)};
//         int a = findlower(nums,0, nums.size() - 1, target);
//         int b = findupper(nums,0, nums.size() - 1, target);
//         return {a, b};
//     }

// };