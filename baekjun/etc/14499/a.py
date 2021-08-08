import sys
input = sys.stdin.readline

N, M, x, y, K = map(int, input().split())

mymap = [0 for i in range(N)]
for i in range(N):
	mymap[i] = list(map(int, input().split()))

dy = [+1, -1, 0, 0]
dx = [0, 0, -1, +1]

dice = [0 for _ in range(7)]

ins = list(map(int, input().split()))
for i in range(K):
	nx = x + dx[ins[i] - 1]
	ny = y + dy[ins[i] - 1]
	if nx >= N or nx < 0 or ny >= M or ny < 0:
		continue
	if ins[i] == 1:
		tmp = dice[4]
		dice[4] = dice[6]
		dice[6] = dice[3]
		dice[3] = dice[1]
		dice[1] = tmp
	elif ins[i] == 2:
		tmp = dice[4]
		dice[4] = dice[1]
		dice[1] = dice[3]
		dice[3] = dice[6]
		dice[6] = tmp
	elif ins[i] == 3:
		tmp = dice[5]
		dice[5] = dice[6]
		dice[6] = dice[2]
		dice[2] = dice[1]
		dice[1] = tmp
	elif ins[i] == 4:
		tmp = dice[5]
		dice[5] = dice[1]
		dice[1] = dice[2]
		dice[2] = dice[6]
		dice[6] = tmp

	if mymap[nx][ny] == 0:
		mymap[nx][ny] = dice[6]
	else:
		dice[6] = mymap[nx][ny]
		mymap[nx][ny] = 0
	print(dice[1])
	x = nx
	y = ny
