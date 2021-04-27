// log_3{n}의 시간복잡도
// log_3{n}의 공간복잡도?(재귀 호출할 때마다)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0 || (n != 1 && n % 3 != 0) )
            return false;
        else if (n == 1)
            return true;
        else
            return isPowerOfThree(n / 3);
    }
};