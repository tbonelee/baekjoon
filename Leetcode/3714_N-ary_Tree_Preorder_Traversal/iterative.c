struct Node {
	int val;
	int numChildren;
	struct Node** children;
};

#include <stdlib.h>

void dfs(struct Node* root, int arr[], int* returnSize);

int* preorder(struct Node* root, int* returnSize) {

	int arr[10000];
	*returnSize = 0;
	if (root == NULL)
		return (NULL);
	arr[*returnSize] = root->val;
	*returnSize = 1;

	struct Node *q[10001];
	int qsize = 10000;
	int head = 1;
	int tail = 1;


	for (int i = 0; i < root->numChildren; i++)
	{
		dfs((root->children)[i], arr, returnSize);
	}
	int *ret = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; i++)
		ret[i] = arr[i];
	return (ret);
}


void dfs(struct Node* root, int arr[], int* returnSize)
{
	arr[*returnSize] = root->val;
	*returnSize = *returnSize + 1;
	for (int i = 0; i < root->numChildren; i++)
		dfs((root->children)[i], arr, returnSize);
}