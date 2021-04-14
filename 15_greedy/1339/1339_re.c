#include <stdio.h>
#include <limits.h>
#include <string.h>


void	mergesort(int to_sort[], int start, int end, int alphabet[][8]);
int		compare(int a, int b, int alphabet[][8]);
void	merge(int to_sort[], int start, int mid, int end, int alphabet[][8]);
long long a_to_i(char arr[][9], int alphabet_to_num[], int i);


int main()
{
	char arr[10][9];
	int N;
	int alphabet[26][8] = {0,};
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", arr[i]);
		int j = 0; while (arr[i][j] != 0) j++;
		int temp_j = --j;
		for (; j >= 0; j--)
		{
			alphabet[arr[i][j] - 'A'][temp_j - j]++;
		}
	}
	int to_sort[27];
	for (int i = 0; i < 26; i++)
	{
		to_sort[i] = i;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("=i = %d\n", i);
		for(int j = 0; j < 8; j++)
		{
			printf("[%d] = %d  ", j, alphabet[i][j]);
		}
		printf("\n");
	}



	mergesort(to_sort, 0, 25, alphabet);

	int alphabet_to_num[26];

	// memset(alphabet_to_num, -1, sizeof(alphabet_to_num));
	for (int i = 0; i < 26; i++)
	{
		alphabet_to_num[i] = -1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("alphatonum[%d] = %d\n", i, alphabet_to_num[i]);
		printf("\n");
		i--; i++;
		printf("i = %d, to_sort[i] = %d\n", i, to_sort[i]);
		alphabet_to_num[to_sort[i]] = 9 - i;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%c = %d\n", (char)(i + 'A'), alphabet_to_num[i]);
	}

	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += a_to_i(arr, alphabet_to_num, i);
	}
	printf("%lld\n", sum);


	// for (int k = 0; k < 26; k++)
	// {
	// 	for (int l = 0; l < 8; l++)
	// 	{
	// 		if (alphabet[k][l] > 0)
	// 			alphabet_leng[k] = l + 1;
	// 	}
	// }
}

long long a_to_i(char arr[][9], int alphabet_to_num[], int i)
{
	int j = 0;
	for (; arr[i][j] != 0; j++)
		;
	long long ret = 0;
	long long ten = 1;
	for (int idx = j - 1; idx >= 0; idx--)
	{
		ret += ten * alphabet_to_num[arr[i][idx] - 'A'];
		ten *= 10;
	}
	return ret;
}

void	mergesort(int to_sort[], int start, int end, int alphabet[][8])
{
	if (start == end)
		return ;

	int mid = (start + end) / 2;
// printf("here");
	mergesort(to_sort, start, mid, alphabet);
	mergesort(to_sort, mid + 1, end, alphabet);
	merge(to_sort, start, mid, end, alphabet);
}

int		compare(int a, int b, int alphabet[][8])
{
	if (a == INT_MIN && b == INT_MIN)
		return 0;
	else if (a != INT_MIN && b == INT_MIN)
		return 1;
	else if (a == INT_MIN && b != INT_MIN)
		return -1;

	for (int i = 7; i >= 0; i++)
	{
		if (alphabet[a][i] > alphabet[b][i])
			return 1;
		else if (alphabet[a][i] < alphabet[b][i])
			return -1;
	}
	return 0;
}

void	merge(int to_sort[], int start, int mid, int end, int alphabet[][8])
{
	int min = INT_MIN;
	int temp1[27];
	int temp2[27];
// printf("here");
	int i = start;
	for (; i <= mid; i++)
	{
		temp1[i] = to_sort[i];
	}
	temp1[i] = min;

	int j = mid + 1;
	for (; j <= end; j++)
	{
		temp2[j] = to_sort[j];
	}
	temp2[j] = min;

	int idx = start;
	for (i = start, j = mid + 1; (i != mid + 1 || j != end + 1); idx++)
	{
		// printf("deepest");
		if (compare(temp1[i], temp2[j], alphabet) == 1)
		{
			to_sort[idx] = temp1[i++];
		}
		else
		{
			to_sort[idx] = temp2[j++];
		}
	}

}