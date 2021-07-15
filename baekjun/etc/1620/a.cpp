#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;

string temp;

map <string, int> maps;

string arr[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		maps.insert(pair<string, int>(temp, i + 1));
		arr[i + 1] = temp;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		if (isdigit(temp[0]))
		{
			cout << arr[atoi(temp.c_str())] << "\n";
		}
		else
		{
			cout << maps[temp] << "\n";
		}
	}

}