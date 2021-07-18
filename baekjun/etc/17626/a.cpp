#include <iostream>

using namespace std;

int arr[50001];

void	find(int N)
{
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		arr[i] = arr[i - 1] + 1;
		for (int j = 1; j * j <= i; j++)
		{
			if (arr[i] >= arr[i - j * j] + 1)
				arr[i] = arr[i - j * j] + 1;
		}
	}
	cout << arr[N] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	find(N);
}