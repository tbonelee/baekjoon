#include <iostream>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> alphas;
	int ret = 0;
	for (int i = 0; i < n; i++){
		alphas.assign(26, 0);
		string temp; cin >> temp;
		string cont = " "; cont += temp;
		// cout << cont << "\n\n";
		for (int i = 1; i < cont.size(); i++){
			// cout << cont[i];
			// cout << cont[i] - 'a' << "\n";
			if (cont[i] != cont[i - 1]){
				// cout << " " << alphas[cont[i] - 'a'] << "\n";
				if (alphas[cont[i] - 'a']){
					// cout << "here\n";
					ret++;
					break ;
				}
				alphas[cont[i] - 'a'] = 1;
			}
		}
		// cout << "\n";

	}
	cout << n - ret << "\n";
}