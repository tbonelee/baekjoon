#include <iostream>
#include <string>

using namespace std;

int	count(int &i, int N, int M, string &S)
{
	int idx = i + 1;
	int	cnt = 0;
	while (idx < M)
	{
		if ((idx - i) % 2 == 0)
		{
			if (S[idx] == 'I')
			{
				cnt++;
			}
			else
				break;
		}
		else
		{
			if (S[idx] == 'O')
				;
			else
				break;
		}
		idx++;
	}
	idx--;
	i = idx;
	if (cnt - N + 1 >= 0)
		return (cnt - N + 1);
	else
		return 0;
}

int find(int N, int M, string &S)
{
	int i = 0;
	int	ret = 0;
	for (; i < M; i++)
	{
		if (S[i] == 'I')
		{
			ret += count(i, N, M, S);
		}
	}
	return (ret);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	string S;
	cin >> S;
	getline(cin, S);
	cout << "S = " << S << "\n";
	cout << S[2] << " \n";
	cout << find(N, M, S) << "\n";
}