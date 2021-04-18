#include <stdio.h>

int oper(int n);

int main()
{
	int N; scanf("%d", &N);
	int temp = N;
	int cnt = 1;
	while ((temp = oper(temp)) != N)
		cnt++;
	printf("%d\n", cnt);
}

int oper(int n)
{
	int ten = n / 10;
	int one = n % 10;
	int sum = one + ten;
	int one_sum = sum % 10;
	int ret = one * 10 + one_sum;
	return (ret);
}
