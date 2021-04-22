#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <limits.h>

int rank_of_input(int input, int num_of_list[], int n)
{
	int ret = n;
	for (int i = 0; i < n; i++)
		if (num_of_list[i] == input)
			ret = i;
	return (ret);
}

int todelete(int *votes_of_list, int *old, int n)
{
	int tocomp = votes_of_list[n - 1];
	int i;
	for (i = n - 1; i >= 0 && votes_of_list[i] == tocomp; i--)
		;
	int samenum = n - 1 - i;
	// if (samenum == n)

	int minold = INT_MAX;
	int minidx;
	for (int j = n - samenum; j < n; j++)
	{
		if (old[j] < minold)
		{
			minold = old[j];
			minidx = j;
		}
	}
	return minidx;
}


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int comp(void const *a, void const *b)
{
	int aa = *(int *)a, bb = *(int *)b;
	return (aa - bb);
}

int main()
{
	int n, votenum; scanf("%d\n%d", &n, &votenum);
	int *votes = (int *)malloc(sizeof(int) * votenum);

	memset(votes, 0, sizeof(int) * votenum);
	for (int i = 0; i < votenum; i++)
		scanf("%d", &votes[i]);

	int *list = (int *)malloc(sizeof(int) * n);
	memset(list, 0, sizeof(int) * n);

	int *votes_of_list = (int *)malloc(sizeof(int) * n);
	memset(votes_of_list, 0, sizeof(int) * n);

	int *num_of_list = (int *)malloc(sizeof(int) * n);
	memset(num_of_list, 0, sizeof(int) * n);

	int *old = (int *)malloc(sizeof(int) * n);
	memset(old, 0, sizeof(int) * n);

	for (int i = 0; i < votenum; i++)
	{
		int rank = rank_of_input(votes[i], num_of_list, n);
		if (rank < n)
		{
			votes_of_list[rank]++;
			for (int j = rank; j > 0; j++)
			{
				if (votes_of_list[j] > votes_of_list[j - 1])
				{
					swap(num_of_list + j, num_of_list + j - 1);
					swap(votes_of_list + j, votes_of_list + j - 1);
					swap(old + j, old + j - 1);
				}
				else
					break ;
			}
		}
		else
		{
			int j;
			for (j = n - 1; j >= 0 && votes_of_list[j]; j--)
				;
			if (j >= 0)
			{
				num_of_list[j] = votes[i];
				votes_of_list[j] = 1;
				old[j] = i;
			}
			else
			{
				int deleteidx = todelete(votes_of_list, old, n);
				// int deleteidx = 1;
				num_of_list[deleteidx] = votes[i];
				votes_of_list[deleteidx] = 1;
				old[deleteidx] = i;
				swap(num_of_list + deleteidx, num_of_list + n - 1);
				swap(votes_of_list + deleteidx, votes_of_list + n - 1);
				swap(old + deleteidx, old + n - 1);
			}
		}

	}
	qsort(num_of_list, n, sizeof(int), &comp);
	for (int i = 0; i < n; i++)
		printf("%d ", num_of_list[i]);
	free(votes);
	free(list);
	free(votes_of_list);
	free(num_of_list);
	free(old);
}