// string str;
// str.substr(i, j)를 쓸 때 str의 i부터 j인덱스 중에 str의 범위를 넘어서는 값이 있는 경우 어떻게 되는지?
// https://stackoverflow.com/questions/50548045/find-substring-between-two-indices-in-c
//
// (펌)
// You can do this:

// std::string(&s[start], &s[end+1])
// or this:

// std::string(s.c_str() + start, s.c_str() + end + 1)
// or this:

// std::string(s.begin() + start, s.begin() + end + 1)
// These approaches require that end is less than s.size(), whereas substr() does not require that.

// Don't complain about the +1--ranges in C++ are always specified as inclusive begin and exclusive end.

#include <iostream>

using namespace std;

int main(){
	int ret = 0;
	string str; cin >> str;
	bool cflag, dflag, lflag, nflag, sflag, zflag;
	cflag = dflag = lflag = nflag = sflag = zflag = false;
	bool dflag2 = false;
	int i = 0;
	for (; i < str.size(); i++){
		if (str[i] == 'c'){
			if (str.substr(i, 2) == "c=" || str.substr(i, 2) == "c-")
				i++;
		}else if (str[i] == 'd'){
			if (str.substr(i, 3) == "dz=")
				i += 2;
			else if (str.substr(i, 2) == "d-")
				i++;
		}else if (str[i] == 'l'){
			if (str.substr(i, 2) == "lj")
				i++;
		}else if (str[i] == 'n'){
			if (str.substr(i, 2) == "nj")
				i++;
		}else if (str[i] == 's'){
			if (str.substr(i, 2) == "s=")
				i++;
		}else if (str[i] == 'z'){
			if (str.substr(i, 2) == "z=")
				i++;
		}
		ret++;
	}

	cout << ret << "\n";
}