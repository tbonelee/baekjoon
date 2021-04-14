// 처음에 typedef unsigned int uint 쓰고
// 그 다음에 typedef long long ll을 추가해서 사용.
// 그런데 기존에 temp를 uint로 해놓았던 것을 변경하지 않아서 자꾸 틀린 답 나옴.
// typedef 수정할 때는 빼먹은 것 없는지 체크 주의!

#include <stdio.h>

typedef unsigned long long ll;

ll	calc(int a, int b, int c);

int main()
{
	int a,b,c; scanf("%d %d %d", &a, &b, &c);
	printf("%llu\n", calc(a % c, b, c) % c);
}

ll	calc(int a, int b, int c)
{
	ll temp;
	if (b == 0)
		return (1);
	else if (b % 2 == 0)
	{
		temp = calc(a, b / 2, c);
		temp = (temp * temp) % (ll)c;
		return temp;
	}
	else
	{
		temp = calc(a, b / 2, c);
		temp = temp * temp % c;
		temp = temp * a % c;
		return (temp);
	}
}