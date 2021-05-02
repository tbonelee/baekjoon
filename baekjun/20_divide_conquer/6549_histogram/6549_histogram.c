#include <stdio.h>
#include <limits.h>

int arr[100001];
int n;

typedef long long ll;

ll find(int start, int end);

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			return 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}
		printf("%lld\n", find(1, n));
	}
}

extern inline int min(int a, int b)
{
	return (a < b ? a : b);
}

extern inline ll max(ll a, ll b)
{
	return (a > b ? a : b);
}

ll find(int start, int end)
{
	if (start == end)
		return (arr[start]);
	int mid = (start + end) / 2;
	ll leftmax = find(start, mid);
	ll rightmax = find(mid + 1, end);
	int i_left, i_right, min_height = INT_MAX;
	ll max_size = LLONG_MIN;
	i_left = mid, i_right = mid + 1;
	for (; ; )
	{
		ll size;
		min_height = min(min_height, min(arr[i_left], arr[i_right]));
		// printf("start = %d, end = %d, min_height = %d\n", start,end,min_height);
		// 이 부분에서 ll로 묵시적 변환될 줄 알았는데 되지 않아서 정수 오버플로우 문제 발생
		size = ((ll)i_right - (ll)i_left + 1) * min_height;
		// printf(" size = %lld\n", size);
		max_size = max(max_size, size);
		if (i_left == start && i_right == end)
			break ;
		else if (i_left == start && i_right < end)
			i_right++;
		else if (i_left > start && i_right == end)
			i_left--;
		else
		{
			if (arr[i_left - 1] > arr[i_right + 1])
				i_left--;
			else
				i_right++;
		}

	}
	// printf("start = %d, end = %d, lmax = %lld, rmax = %lld, msize = %lld\n", start, end, leftmax, rightmax, max_size);
	return (max(max(leftmax, rightmax), max_size));
}