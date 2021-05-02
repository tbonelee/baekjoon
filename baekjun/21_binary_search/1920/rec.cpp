// 벡터를 함수 인자로 그냥 넘기는 경우 벡터를 항상 값복사해서 시간이 오래 걸린다.
// 따라서 참조로 넘기는 것이 필요 (이것 때문에 계속 시간초과)

#include <cstdio>
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

int n, m;

int bin_search(int temp, vector<int> &array, int start, int end);

int main(){
	scanf("%d", &n);
	int temp;
	vector<int> array;
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
	int middle = (start + end) / 2;
	if (start > end)
		return 0;
	if (array[middle] == temp)
		return 1;
	else if (array[middle] > temp)
		return bin_search(temp, array, start, middle - 1);
	else
		return bin_search(temp, array, middle + 1, end);
}