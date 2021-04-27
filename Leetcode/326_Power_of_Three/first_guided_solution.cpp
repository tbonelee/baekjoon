// 반복 대입
// 시간복잡도 O(log3{n})
// 공간복잡도 O(1)

class Solution {
public:
    bool isPowerOfThree(int n) {
		if (n < 1)
			return false;

		while (n % 3 == 0){
			n /= 3;
		}
		return n == 1;
    }
};