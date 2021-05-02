#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> first;
	first.resize(n);
	for (int i = 0; i < n; i++)
		cin >> first[i];

	sort(first.begin(), first.end());

	vector<string> final;
	string temp;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		if (binary_search(first.begin(), first.end(), temp))
			final.push_back(temp);
	}
	sort(final.begin(), final.end());
	printf("%ld\n", final.size());
	for (int i = 0; i < final.size(); i++)
	{
		printf("%s\n", final[i].c_str());
	}

}