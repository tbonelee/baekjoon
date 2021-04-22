// void duplicateZeros(int* arr, int arrSize){
// 	for (int i = 0; i < arrSize; i++){
// 		if (!arr[i]){
// 			for (int j = arrSize - 1; j >= i + 2 && j < arrSize; j--){
// 				arr[j] = arr[j - 1];
// 			}
// 			arr[++i] = 0;
// 		}
// 	}
// }

void duplicateZeros(int* arr, int arrSize){
	int leng = arrSize;
	int numZero = 0;
	int boundflag = 0;
	for (int i = 0; i < arrSize && i + numZero < arrSize; i++){
		if (arr[i] == 0){
			if (i + numZero + 1 < leng){
				numZero++;
			}
			else if (i + numZero + 1 == leng){
				arr[leng-- - 1] = 0;
			}
		}
	}
	int i = leng - 1 - numZero, j = leng - 1;
	for (; i >= 0; ){
		if (arr[i] == 0){
			arr[j--] = arr[i];
			arr[j] = 0;

		}
		else{
			arr[j] = arr[i];
		}
		i--;
		j--;
	}
}