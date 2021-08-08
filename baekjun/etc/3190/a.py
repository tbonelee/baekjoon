import sys
input = sys.stdin.readline

APPLE = int(-1)
DOWN = int(2)
LEFT = int(3)
UP = int(4)
RIGHT = int(5)

N = int(input())
K = int(input())
apple_pos = []
for _ in range(K):
	apple_pos.append(list(map(int, input().split())))
L = int(input())
q = []
for _ in range(L):
	tmp = input().split()
	tmp[0] = int(tmp[0])
	q.append(tmp)

board = [[0] * (N + 1) for _ in range(N + 1)]

for i in range(K):
	if apple_pos[i][0] < 1 or apple_pos[i][0] > N or apple_pos[i][1] < 1 or apple_pos[i][1] > N:
		continue
	board[apple_pos[i][0]][apple_pos[i][1]] = APPLE
board[1][1] = RIGHT
head_pos = [1] * 2
tail_pos = [1] * 2
elapsed_sec = 0
direction = RIGHT

while True:
	elapsed_sec += 1
	if direction == RIGHT:
		head_pos[1] += 1
	elif direction == LEFT:
		head_pos[1] -= 1
	elif direction == UP:
		head_pos[0] -= 1
	elif direction == DOWN:
		head_pos[0] += 1

	if head_pos[0] < 1 or head_pos[0] > N or head_pos[1] < 1 or head_pos[1] > N:
		break
	elif board[head_pos[0]][head_pos[1]] > 0:
		break

	if board[head_pos[0]][head_pos[1]] == 0:
		tmp = board[tail_pos[0]][tail_pos[1]]
		board[tail_pos[0]][tail_pos[1]] = 0
		if tmp == DOWN:
			tail_pos[0] += 1
		elif tmp == UP:
			tail_pos[0] -= 1
		elif tmp == LEFT:
			tail_pos[1] -= 1
		elif tmp == RIGHT:
			tail_pos[1] += 1

	if elapsed_sec == q[0][0]:
		tmp = q[0][1]
		q.pop(0)
		if tmp == 'L':
			if direction == DOWN:
				direction = RIGHT
			else:
				direction -= 1
		else:
			if direction == RIGHT:
				direction = DOWN
			else:
				direction += 1
	board[head_pos[0]][head_pos[1]] = direction

print(elapsed_sec)