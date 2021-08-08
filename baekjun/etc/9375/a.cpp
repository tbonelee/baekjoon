#include <iostream>
#include <unordered_map>

using namespace std;

int T;
unordered_map<string, int> my_map;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		string tmp1, tmp2;
		my_map.clear();
		for (int j = 0; j < n; j++)
		{
			cin >> tmp1 >> tmp2;
			if (my_map.count(tmp2) == 0)
			{
				my_map[tmp2] = 1;
			}
			else
			{
				my_map[tmp2]++;
			}
		}
		int ret = 1;
		for (auto i = my_map.begin(); i != my_map.end(); i++)
		{
			ret *= (i->second + 1);
		}
		cout << ret - 1 << "\n";
	}

}
