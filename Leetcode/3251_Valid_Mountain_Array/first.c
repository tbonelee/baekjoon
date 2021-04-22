bool validMountainArray(int* arr, int arrSize){
	if (arrSize < 3)
		return false;
	int ascflag = 1;
	int descflag = 0;
	for (int i = 1; i < arrSize; i++){
		if (ascflag == 1){
			if (arr[i] < arr[i - 1]){
				ascflag = 0;
				descflag = 1;
				if (i == 1)
					return false;
			}
			else if (arr[i] == arr[i - 1])
				return false;
		}
		else if (descflag == 1){
			if (arr[i] >= arr[i - 1])
				return false;
		}
	}
	if (ascflag == 0)
		return true;
	else
		return false;
}