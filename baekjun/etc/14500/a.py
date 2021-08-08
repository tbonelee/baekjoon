import sys
input = sys.stdin.readline

N, M = map(int, input().split())

mymap = []

for _ in range(N):
	mymap.append(list(map(int, input().split())))

ret = 0

for i in range(N):
	for j in range(M):
		if i + 3 < N:
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 2][j] + mymap[i + 3][j]
			if tmp > ret:
				ret = tmp
		if j + 3 < M:
			tmp = mymap[i][j] + mymap[i][j + 1] + mymap[i][j + 2] + mymap[i][j + 3]
			if tmp > ret:
				ret = tmp
		if i + 1 < N and j + 1 < M:
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 1][j + 1] + mymap[i][j + 1]
			if tmp > ret:
				ret = tmp
		if i + 2 < N and j + 1 < M:
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 2][j] + mymap[i + 2][j + 1]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 1][j + 1] + mymap[i + 2][j + 1]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 2][j] + mymap[i + 1][j + 1]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 2][j] + mymap[i][j + 1]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i][j + 1] + mymap[i + 1][j + 1] + mymap[i + 2][j + 1]
			if tmp > ret:
				ret = tmp
		if i + 2 < N and j - 1 >= 0:
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 2][j] + mymap[i + 2][j - 1]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 1][j - 1] + mymap[i + 2][j - 1]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 2][j] + mymap[i + 1][j - 1]
			if tmp > ret:
				ret = tmp
		if i + 1 < N and j + 2 < M:
			tmp = mymap[i][j] + mymap[i][j + 1] + mymap[i][j + 2] + mymap[i + 1][j]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i][j + 1] + mymap[i][j + 2] + mymap[i + 1][j + 2]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 1][j + 1] + mymap[i + 1][j + 2]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i][j + 1] + mymap[i + 1][j + 1] + mymap[i + 1][j + 2]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i][j + 1] + mymap[i][j + 2] + mymap[i + 1][j + 1]
			if tmp > ret:
				ret = tmp
		if i + 1 < N and j - 2 >= 0:
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 1][j - 1] + mymap[i + 1][j - 2]
			if tmp > ret:
				ret = tmp
			tmp = mymap[i][j] + mymap[i][j - 1] + mymap[i + 1][j - 1] + mymap[i + 1][j - 2]
			if tmp > ret:
				ret = tmp
		if i + 1 < N and j - 1 >= 0 and j + 1 < M:
			tmp = mymap[i][j] + mymap[i + 1][j] + mymap[i + 1][j - 1] + mymap[i + 1][j + 1]
			if tmp > ret:
				ret = tmp

print(ret)