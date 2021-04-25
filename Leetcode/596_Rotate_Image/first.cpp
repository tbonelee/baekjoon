// 새로운 2차원 매트릭스를 동적 배열하면 안 된다는 문제 조건

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int length = matrix.size();
		int temp1, temp2, temp3;
        // std::cout << length << endl;
		for (int k = 0; k < length / 2; k++){
			for (int j = k; j < length - k - 1; j++){
				int depth = k, pos = j;
				temp1 = matrix[pos][length - 1 - depth];
				matrix[pos][length - 1 - depth] = matrix[depth][pos];
				temp2 = matrix[length - 1 - depth][length - 1 - pos];
				matrix[length - 1 - depth][length - 1 - pos] = temp1;
				temp3 = matrix[length - 1 - pos][depth];
				matrix[length - 1 - pos][depth] = temp2;
				matrix[depth][pos] = temp3;
			}
		}
    }
};