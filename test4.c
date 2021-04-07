void find_max_crossing_subarray(int A[], int low, int mid, int high, int *max_left, int *max_right, int *max_sum)
{
	int left_sum = -2147483648;
	int sum = 0;
	*max_left = mid;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			*max_left = i;
		}
	}

	int right_sum = -2147483648;
	sum = 0;
	*max_right = mid + 1;
	for (int j = mid + 1; j <= high; j++)
	{
		sum = sum + A[j];
		if (sum > right_sum)
		{
			right_sum = sum;
			*max_right = j;
		}
	}

	*max_sum = left_sum + right_sum;
}

void find_maximum_subarray(int A[], int low, int high, int *max_left, int *max_right, int *max_sum)
{
	int mid;
	int *left_max_left, *left_max_right, *left_max_sum;
	int *right_max_left, *right_max_right, *right_max_sum;
	int *cross_max_left, *cross_max_right, *cross_max_sum;

	if (high == low)
	{
		*max_left = low; *max_right = high; *max_sum = A[high];
	}
	else
	{
		mid = (low + high) / 2;
		find_maximum_subarray(A, low, mid, left_max_left, left_max_right, left_max_sum);
		find_maximum_subarray(A, mid + 1, high, right_max_left, right_max_right, right_max_sum);
		find_max_crossing_subarray(A, low, mid, high, cross_max_left, cross_max_right, cross_max_sum);

		if (*left_max_sum >= *right_max_sum && *right_max_sum >= *cross_max_sum)
		{
			*max_left = *left_max_left; *max_right = *left_max_right; *max_sum = *left_max_sum;
		}
		else if (*right_max_sum >= *left_max_sum && *left_max_sum >= *cross_max_sum)
		{
			*max_left = *right_max_left; *max_right = *right_max_right; *max_sum = *right_max_sum;
		}
		else
		{
			*max_left = *cross_max_left; *max_right = *cross_max_right; *max_sum = *cross_max_sum;
		}
	}
}