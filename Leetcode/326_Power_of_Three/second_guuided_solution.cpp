// 3의 배수이면 3진법에서 한 자리면 1이고 나머지는 0
// int to string in base 3기능의 함수가 있으면 이를 사용.
// 없으면 다음과 같이 가능할듯
// 첫번째 해설과 동일한 시간/공간 복잡도

class Solution {
public:
    bool isPowerOfThree(int n) {
		if (n < 1)
			return false;
        int cnt1 = 0;
		int cnt2 = 0;
		while (n){
			if (n % 3 == 1)
				cnt1++;
			if (n % 3 == 2)
				cnt2++;
			n /= 3;
		}
		return cnt1 == 1 && cnt2 == 0;
    }
};