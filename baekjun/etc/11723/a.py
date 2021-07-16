import sys
input = sys.stdin.readline

S = 0
M = int(input())
for i in range(1, M+1):
	arr = input().split()
	if arr[0] == 'add':
		S |= (1 << (int(arr[1]) - 1))
	elif arr[0] == 'remove':
		S &= ~(1 << (int(arr[1]) - 1))
	elif arr[0] == 'check':
		print(1 if (S & (1 << (int(arr[1]) - 1))) > 0 else 0)
	elif arr[0] == 'toggle':
		if S & (1 << (int(arr[1]) - 1)) > 0:
			S &= ~(1 << (int(arr[1]) - 1))
		else:
			S |= (1 << (int(arr[1]) - 1))
	elif arr[0] == 'all':
		S |= 0b11111111111111111111
	elif arr[0] == 'empty':
		S &= 0
		print (arr[1])