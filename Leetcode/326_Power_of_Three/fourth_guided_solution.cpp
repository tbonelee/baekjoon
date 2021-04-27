// 정수 범위 내에서 가장 큰 3의 제곱수는?

// 3^{log3{INT_MAX}}는 3^19 == 1162261467
// 이 수를 n으로 나눈 나머지가 0이면 true

// O(1)의 시간/공간 복잡도

// 3 대신 다른 소수도 가능. 허나 소수가 아닌 수는 불가능

    class Solution {
    public:
        bool isPowerOfThree(int n) {
			return n > 0 && 1162261467 % n == 0;
        }
    };