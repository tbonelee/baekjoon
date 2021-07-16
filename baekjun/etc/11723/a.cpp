#include <iostream>
#include <cstring>

using namespace std;

int M;
int S;
string cmd, num;

void do_add(int &S)
{
	cin >> num;
	S |= (1 << (atoi(num.c_str()) - 1));
}

void do_remove(int &S)
{
	cin >> num;
	S &= ~(1 << (atoi(num.c_str()) - 1));
}

void do_check(int &S)
{
	cin >> num;
	if ((S & (1 << (atoi(num.c_str()) - 1))) > 0)
		cout << "1\n";
	else
		cout << "0\n";
}

void do_toggle(int &S)
{
	cin >> num;
	if ((S & (1 << (atoi(num.c_str()) - 1))) > 0)
	{
		S &= ~(1 << (atoi(num.c_str()) - 1));
	}
	else
	{
		S |= (1 << (atoi(num.c_str()) - 1));
	}
}

void do_all(int &S)
{
	S |= 0b11111111111111111111;
}

void do_empty(int &S)
{
	S &= 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	S = 0;
	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> cmd;
		if (strcmp(cmd.c_str(), "add") == 0)
			do_add(S);
		else if (strcmp(cmd.c_str(), "remove") == 0)
			do_remove(S);
		else if (strcmp(cmd.c_str(), "check") == 0)
			do_check(S);
		else if (strcmp(cmd.c_str(), "toggle") == 0)
			do_toggle(S);
		else if (strcmp(cmd.c_str(), "all") == 0)
			do_all(S);
		else
			do_empty(S);
	}
}