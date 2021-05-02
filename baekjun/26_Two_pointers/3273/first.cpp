// 투포인터 풀이 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, x;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> lists(n);
	for (int i = 0; i < n; i++)
		cin >> lists[i];
	cin >> x;
	int start, end;
	start = 0; end = n - 1;
	sort(lists.begin(), lists.end());
	// for (int i = 0; i < n; i++)
	// 	cout << lists[i] << " ";
	// cout << "\n";
	int ret = 0;
	while (start < end){
		if (lists[start] + lists[end] == x){
			ret++;
			end--;
		}else if (lists[start] + lists[end] < x)
			start++;
		else
			end--;
	}
	cout << ret << "\n";
}