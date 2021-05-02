// dp[i][j] i는 추의 인덱스, j는 무게 단위
// 새로운 추가 추가 되면 기존에 있던 추들로 측정할 수 있는 무게에 새 추의 무게를 더한 것과 뺀 무게도 측정 가능
// 역관계도 체크

#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main(){
	cin >> n;
	vector<int> choo(n);
	for (int i = 0; i < n; i++)
		cin >> choo[i];
	cin >> k;
	vector<int> bids(k);
	int max = -1;
	for (int i = 0; i < k; i++){
		cin >> bids[i];
		// if (bids[i] > max)
		// 	max = bids[i];
	}
	max = 40510;
		int sum = 0;
	vector<vector<int> > memo(n, vector<int>(max + 1, -1));
	for (int i = 0; i < n; i++)
		memo[i][0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= max; j++){
			if (i == 0){
				memo[i][choo[i]] = 1;
			}
			else if (i >= 1 && memo[i - 1][j] == 1){
				memo[i][j] = 1;
				if (j - choo[i] >= 1)
					memo[i][j - choo[i]] = 1;
				if (j + choo[i] <= max)
					memo[i][j + choo[i]] = 1;
				if (choo[i] - j >= 1)
					memo[i][choo[i] - j] = 1;
			}
		}
	}
	// cout << "max = "<< max << "\n";
	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j <= 10; j++){
	// 		cout << "(" << i << ", " << j << " = " << memo[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "n - 1 = " << n - 1<< "\n";
	// cout << choo[0] << "\n";
	// cout << choo[1] << "\n";
	// cout << "memo[n - 1][choo[0]] = " << memo[n - 1][choo[0]] << "\n";
	// cout << "memo[n - 1][choo[1]] = " << memo[n - 1][choo[1]] << "\n";
	for (int i = 0; i < k; i++){
		if (memo[n - 1][bids[i]] == 1)
			cout << "Y ";
		else
			cout << "N ";
	}
	cout << "\n";
}