// min{인수 2의 갯수, 인수 5의 갯수}를 구하는 문제로 생각

#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;
	int two_five[2] = {0,0};
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		for (; temp % 2 == 0; temp /= 2)
		{
			two_five[0]++;
		}
		for (; temp % 5 == 0; temp /= 5)
		{
			two_five[1]++;
		}
	}
	int ret = two_five[0] < two_five[1] ? two_five[0] : two_five[1];
	cout << ret << endl;
}