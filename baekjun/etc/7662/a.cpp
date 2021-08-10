#include <iostream>
#include <unordered_map>
#include <cstring>
#include <queue>

using namespace std;

#define EMPTY 3000000000

int T, k;

unordered_map<int, int> lst;

// long long lst[1000001];

priority_queue<int> maxval;
priority_queue<int, vector<int>, greater<int> > minval;

void insert(int n)
{
	int tmp;
	if (lst.count(n) == 0)
		lst[n] = 1;
	else
		lst[n] = lst[n] + 1;
	insert_min:
		if (minval.empty())
		{
			minval.push(n);
		}
		else
		{
			int tmp2 = 0;
			tmp2 = minval.top();
			if (lst.count(tmp2) == 0)
			{
				minval.pop();
				goto insert_min;
			}
			if (n < minval.top())
				minval.push(n);
		}
	insert_max:
		if (maxval.empty())
		{
			maxval.push(n);
		}
		else
		{
			int tmp3 = 0;
			tmp3 = maxval.top();
			if (lst.count(tmp3) == 0)
			{
				maxval.pop();
				goto insert_max;
			}
			if (n > maxval.top())
				maxval.push(n);
		}

}

void delete_min()
{
	if (lst.empty())
		return ;
	heremin:
		int tmp = minval.top();
		if (lst.count(tmp) == 0)
		{
			minval.pop();
			goto heremin;
		}

		if (lst[tmp] == 1)
		{
			lst.erase(tmp);
			minval.pop();
		}
		else
		{
			lst[tmp] -= lst[tmp];
		}
}

void delete_max()
{
	if (lst.empty())
		return ;
	heremax:
		int tmp = maxval.top();
		if (lst.count(tmp) == 0)
		{
			maxval.pop();
			goto heremax;
		}

		if (lst[tmp] == 1)
		{
			lst.erase(tmp);
			maxval.pop();
		}
		else
		{
			lst[tmp] -= lst[tmp];
		}
}

void my_delete(int n)
{
	if (n == -1)
		delete_min();
	else
		delete_max();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++){
		lst.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++){
			char chartmp;
			int inttmp;
			cin >> chartmp >> inttmp;
			if (chartmp == 	'I')
				insert(inttmp);
			else if (chartmp == 'D')
				my_delete(inttmp);
		}
		// cout << "comeout \n";
		int maxret, minret;
		if (!lst.empty()){

			finalmax:
				maxret = maxval.top();
				if (lst.count(maxret) == 0)
				{
					maxval.pop();
					goto finalmax;
				}
			finalmin:
				minret = minval.top();
				if (lst.count(minret) == 0)
				{
					minval.pop();
					goto finalmin;
				}
				cout << maxret << " " << minret << "\n";
		}else{
			cout << "EMPTY\n";
		}
	}

}