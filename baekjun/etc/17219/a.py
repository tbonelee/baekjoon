import sys

diction = {}

N, M = map(int, input().split())

for _ in range(N):
	tmp = sys.stdin.readline().split()
	diction[tmp[0]] = tmp[1]

for _ in range(M):
	print(diction[input()])