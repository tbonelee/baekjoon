#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

// +-*순서
int opcases[3][6] = {{1, 1, 2, 3, 2, 3}, {2, 3, 1, 1, 3, 2}, {3, 2, 3, 2, 1, 1}};

// op1이 op2보다 우선순위면 음수 반환
int oper_comp(int cases, char op1, char op2){
	int idx1, idx2;
	if (op1 == '+') idx1 = 0; else if (op1 == '-') idx1 = 1; else idx1 = 2;
	if (op2 == '+') idx2 = 0; else if (op2 == '-') idx2 = 1; else idx2 = 2;
	return (opcases[idx1][cases] - opcases[idx2][cases]);
}

long long calc(long long a, long long b, char op){
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else
		return a * b;
}

long long solve(vector<string>cont){
	stack<long long> s;
	for (auto &elem : cont){
		if (isdigit(elem[0])){
			// long long temp = stoll(elem);
			s.push(stoll(elem));
		}else{
			long long b = s.top(); s.pop();
			long long a = s.top(); s.pop();
			s.push(calc(a, b, elem[0]));
		}
	}
	return (s.top());
}

long long solution(string expression) {
	vector<char> op;
	vector<int> num;
    long long answer = 0;
	for (int cases = 0; cases < 6; cases++){
		vector<string>cont;
		stack<char>st;
		string temp = "";
		for (int i = 0; i < expression.size(); i++){
			if (!isdigit(expression[i])){
				cont.push_back(temp);
				temp = "";
				while(!st.empty() && oper_comp(cases, st.top(), expression[i]) <= 0){
					string op_temp = "";
					op_temp += st.top();
					cont.push_back(op_temp);
					st.pop();
				}
				st.push(expression[i]);
			}else{
				temp += expression[i];
			}
		}
		cont.push_back(temp);
		while(!st.empty()){
			string op_temp = "";
			op_temp += st.top();
			cont.push_back(op_temp);
			st.pop();
		}
		// cout << abs(solve(cont)) << " ";
		answer = max(answer, abs(solve(cont)));
		// cout << answer << "\n\n";
		// for (auto& temp : cont)
		// 	cout << temp << " ";
		// cout << endl << endl;
	}
    return answer;
}

int main(){
	string expression = "100-200*300-500+20";


	cout << solution(expression); cout.flush();
	// printf("%lld\n", solution(expression));
	// cout << solution(expression);
	return 0;
}