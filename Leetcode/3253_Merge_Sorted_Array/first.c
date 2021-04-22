#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int *temp = (int *)malloc(sizeof(int) * (m + n));
	int idx = 0, i = 0, j = 0;
	for (; i < m && j < n; idx++){
		if (nums1[i] < nums2[j])
			temp[idx] = nums1[i++];
		else
			temp[idx] = nums2[j++];
	}
	if (i < m)
		for (; i < m; i++)
			temp[idx++] = nums1[i];
	if (j < n)
		for (; j < n; j++)
			temp[idx++] = nums2[j];
	for (int i = 0; i < m + n; i++)
		nums1[i] = temp[i];
	free(temp);
}