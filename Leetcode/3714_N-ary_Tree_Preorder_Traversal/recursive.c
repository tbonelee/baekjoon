/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

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

typedef struct Node t_node;

int main()
{
	int num = 1;
	t_node *root = malloc(sizeof(t_node));
	root->val = 0;
	root->numChildren = 0;
	root->children = NULL;
	t_node q[200];
	int head = 1, tail = 1;
	for (int i = 1; i < 100; i++)
	{
		t_node *left = malloc(sizeof(t_node));
		t_node *right = malloc(sizeof(t_node));

		left->val = ++num;
		right->val = ++num;

	}
}