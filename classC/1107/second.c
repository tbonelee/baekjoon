#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m;

int main()
{
	char str[7];
	scanf("%s", str);
	scanf("%d", &m);
	int arr[10];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < m; i++)
	{
		int temp; scanf("%d", &temp);
		arr[temp] = -1;
	}
	printf("===================\n");
	for (int i = 0; i <= 9; i++)
		printf("arr[%d] = %d\n", i, arr[i]);


	int mindigit = 0, maxdigit = 9;
	int d;
	for(d = 0; arr[d] == -1; d++)
		;
	mindigit = d;
	for (d = 9; arr[d] == -1; d--)
		;
	maxdigit = d;
	printf("====================\nmindigit = %d, maxdigit = %d\n", mindigit, maxdigit);
	// +-버튼으로만 움직일 때의 횟수
	n = atoi(str);
	printf("n = %d\n", n);
	int cnt_simple = n > 100 ? n - 100 : 100 - n;
	printf("cnt_simple = %d\n", cnt_simple);

	////////////////////////////////////////////////////
	char up[7], down[7], comp[7];
	int cnt_up = 0, cnt_down = 0;
	int i;
	for (i = 0; str[i]; i++)
	{
		if (arr[str[i] - '0'] == 0)
		{
			comp[i] = str[i];
			up[i] = str[i];
			down[i] = str[i];
			cnt_up++;
			cnt_down++;
		}
		else
			break;
	}
	comp[i] = str[i];
	for (int ii = i + 1; ii < (int)strlen(str); ii++)
		comp[ii] = '0';
	comp[strlen(str)] = 0;
	printf("compatoi = %d, compstr = %s\n", atoi(comp), comp);


	






	// int pos = i;
	int pos = strlen(str) - i;
	for (; i < (int)strlen(str); i++)
	{
		up[i] = '0';
		down[i] = '0';
	}
	up[i] = 0;
	down[i] = 0;
	printf("upstr = %s, downstr = %s\n", up, down);
	printf("pos = %d, up = %d, down = %d\n", pos, atoi(up), atoi(down));





	// int up_flag = 1;
	// int down_flag = 1;
	// if (str[i] != 0)
	// {
	// 	int j;
	// 	for (j = str[i] - '0' + 1; j <= 9 && arr[j] == -1; j++)
	// 		;
	// 	if (j == 10)
	// 		up_flag = 0;
	// 	if (up_flag == 1)
	// 	{
	// 		int temp = i;
	// 		up[temp++] = j + '0';
	// 		cnt_up++;
	// 		for (; str[temp]; temp++)
	// 		{
	// 			up[temp] = mindigit + '0';
	// 			cnt_up++;
	// 		}
	// 	}


	// 	int k;
	// 	for (k = str[i] - '0' - 1; k >= 0 && arr[k] == -1; k--)
	// 		;
	// 	if (k == -1)
	// 		down_flag = 0;
	// 	if (down_flag == 1)
	// 	{
	// 		int temp = i;
	// 		down[temp++] = k + '0';
	// 		cnt_down++;
	// 		for (; str[temp]; temp++)
	// 		{
	// 			down[temp] = maxdigit + '0';
	// 			cnt_down++;
	// 		}
	// 	}
	// }
	// up[strlen(str)] = 0;
	// down[strlen(str)] = 0;
	// printf("upflag = %d, up = %s\ndownflag = %d, down = %s\n", up_flag, up, down_flag, down);
	// int num_up = atoi(up);
	// int num_down = atoi(down);
	// cnt_up += n > num_up ? n - num_up : num_up - n;
	// cnt_up += num_up - n;
	// cnt_down += n > num_down ? n - num_down : num_down - n;
	// cnt_down += n - num_down;
	// printf("cnt_up = %d\ncnt_down = %d\n", cnt_up, cnt_down);
	// int min = cnt_simple;
	// if (up_flag == 1)
	// 	min = min < cnt_up ? min : cnt_up;
	// if (down_flag == 1)
	// 	min = min < cnt_down ? min : cnt_down;
	// printf("======================\n");
	// printf("%d\n", min);

}