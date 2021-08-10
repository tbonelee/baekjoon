#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, k;

int check[1000001];



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++){
		memset(check, 0, sizeof(check));
		priority_queue<pair<int, int> > maxval;
		priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > minval;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++){git
			char chartmp;
			int inttmp;
			cin >> chartmp >> inttmp;
			if (chartmp == 	'I'){
				minval.push({inttmp, i});
				maxval.push({inttmp, i});
				check[i] = 1;
			}
			else if (chartmp == 'D'){
				if (inttmp == 1){

					if (!maxval.empty()){
						check[maxval.top().second] = 0;
						maxval.pop();

					}
					while (!maxval.empty() && check[maxval.top().second] == 0){
						maxval.pop();
					}
					while (!minval.empty() && check[minval.top().second] == 0){
						minval.pop();
					}
				}
				else if (inttmp == -1){
					if (!minval.empty()){
						check[minval.top().second] = 0;
						minval.pop();
					}

					while (!maxval.empty() && check[maxval.top().second] == 0){
						maxval.pop();
					}
					while (!minval.empty() && check[minval.top().second] == 0){
						minval.pop();
					}


				}
			}
		}
		if (!minval.empty() && !maxval.empty()){
			cout << maxval.top().first << " " << minval.top().first << "\n";

		}else{
			cout << "EMPTY\n";
		}
	}
}