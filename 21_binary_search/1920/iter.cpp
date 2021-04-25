#include <cstdio>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

int n, m;

int bin_search(int temp, vector<int> &array, int start, int end);

int main(){
	scanf("%d", &n);
	vector<int> array;
	int temp;
	for (int i = 0; i < n; i++){
		scanf("%d", &temp);
		array.push_back(temp);
	}
	sort(array.begin(), array.end());
	// printf("array.begin = %d, array.end = %d\n", *array.begin(), *(array.end() - 1));
	// printf("array.size() = %ld\n", array.size());
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &temp);
		if (*array.begin() > temp || *(array.end() - 1) < temp)
			printf("0\n");
		else
			printf("%d\n",bin_search(temp, array, 0, array.size() - 1));
	}

}

int bin_search(int temp, vector<int> &array, int start, int end){
	while (1){
		int middle = (start + end) / 2;
		if (start > end)
			return 0;
		if (array[middle] == temp)
			return 1;
		else if (array[middle] > temp)
			end = middle - 1;
		else
			start = middle + 1;
	}

}