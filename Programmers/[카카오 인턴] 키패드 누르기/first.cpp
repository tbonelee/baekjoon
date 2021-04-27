#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
	bool lefterian;
	if (hand.front() == 'l')
		lefterian = true;
	else
		lefterian = false;
	pair<int, int>l_hand(3, 0);
	pair<int, int>r_hand(3, 2);
	int leng = numbers.size();
	for (int i = 0; i < leng; i++){
		if (numbers[i] % 3 == 1){
			answer.push_back('L');
			l_hand.first = numbers[i] / 3;
			l_hand.second = 0;
		}else if (numbers[i] % 3 == 0 && numbers[i]){
			answer.push_back('R');
			r_hand.first = numbers[i] / 3 - 1;
			r_hand.second = 2;
		}else{
			int xaxis;
			if (numbers[i] % 3 == 2)
				xaxis = numbers[i] / 3;
			else
				xaxis = 3;
			int ldist = abs(xaxis - l_hand.first) + abs(1 - l_hand.second);
			int rdist = abs(xaxis - r_hand.first) + abs(1 - r_hand.second);
			if (ldist < rdist){
				answer.push_back('L');
				l_hand.first = xaxis;
				l_hand.second = 1;
			}else if (ldist > rdist){
				answer.push_back('R');
				r_hand.first = xaxis;
				r_hand.second = 1;
			}else {
				if (lefterian){
					answer.push_back('L');
					l_hand.first = xaxis;
					l_hand.second = 1;
				}else{
					answer.push_back('R');
					r_hand.first = xaxis;
					r_hand.second = 1;
				}
			}
		}
	}

    return answer;
}