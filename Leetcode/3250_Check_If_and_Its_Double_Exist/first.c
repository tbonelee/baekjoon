bool checkIfExist(int* arr, int arrSize){
	bool ret = false;
	for (int i = 0; i < arrSize - 1; i++){
		for (int j = i + 1; j < arrSize; j++){
			if (arr[i] == 2 * arr[j]){
				ret = true;
				break;
			}
			else if (arr[j] == 2 * arr[i]){
				ret = true;
				break;
			}
		}
		if (ret == true)
			break ;
	}
	return (ret);
}