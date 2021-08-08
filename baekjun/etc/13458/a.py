import sys
input = sys.stdin.readline

N = int(input())
A = []
A = list(map(int, input().split()))

B, C = map(int, input().split())

ret = 0

for i in range(N):
	A[i] -= B
	if A[i] <= 0:
		ret += 1
	else:
		if A[i] % C > 0:
			ret += A[i] // C + 2
		else:
			ret += A[i] // C + 1
print(ret)