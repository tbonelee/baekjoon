// 처음에는 배열을 차례대로 돌면서 우선순위큐에 넣고(클수록 높은 순위) 우선순위 큐.top의 원소가 현재 참조중인 가격보다 높으면 거기서부터 큐에서 팝하면서(현재 참조중인 가격보다 높지 않을때까지) 답을 적으면 된다고 생각.

// 그런데 굳이 우선순위 큐를 쓰지 않고 스택을 써도 가능.
// 만약 스택 최상단에 있는 원소(a로 지칭)가 그 바로 밑에 있는 원소(b)보다 작다고 해보자.
// 그런 경우가 있다면 현재 참조하고 있는 가격이 a 이상이고 b보다 작은 경우, b의 답을 기록해야 하는데 기록하지 못하므로 오류가 생긴다.
// 하지만 a를 푸시할 때 b가 최상단에 있었을 것이고 a가 b보다 작으므로 b에 답을 기록하고 b를 pop하게 된다.
// 따라서 O(log n)(n은 배열 길이)의 정렬이 필요한 우선순위 큐보다 정렬을 사용하지 않는 스택을 쓰는 것이 훨씬 효율적

#include <string>
#include <vector>
#include <stack>

using namespace std;


vector<int> solution(vector<int> prices) {
    vector<int> answer;
	int leng = prices.size();
	answer.resize(leng);
	stack<int> st;
	for (int i = 0; i < leng; i++){
		while (!st.empty() && prices[st.top()] > prices[i]){
			answer[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		answer[st.top()] = leng - 1 - st.top();
		st.pop();
	}

    return answer;
}