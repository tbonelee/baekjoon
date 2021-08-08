import sys
import copy
input = sys.stdin.readline

N, M = map(int, input().split())

my_map = []

for _ in range(N):
	my_map.append(list(map(int, input().split())))

emptypos = []
queue = []
for i in range(N):
	for j in range(M):
		if my_map[i][j] == 0:
			emptypos.append([i, j])
		elif my_map[i][j] == 2:
			queue.append([i, j])
num_empty = len(emptypos)
# print(queue)

ret = 0
to_subtract = 0
def find():
	global ret, queue
	di = [0, 0, -1, 1]
	dj = [-1, 1, 0, 0]
	# queue_copy = copy.deepcopy(queue)
	queue_copy = queue.copy()
	# print(queue_copy)

	global N, M
	global my_map
	visited = [[0 for _ in range(M)] for __ in range(N)]
	to_subtract = 0
	while queue_copy:
		tmp = queue_copy[0]
		queue_copy.pop(0)
		for idx in range(4):
			i = tmp[0] + di[idx]
			j = tmp[1] + dj[idx]
			if not (i >= 0 and i < N and j >= 0 and j < M):
				continue
			if my_map[i][j] == 0 and visited[i][j] == 0:
				# print(i, j)
				to_subtract += 1
				visited[i][j] = 1
				queue_copy.append([i, j])
	if num_empty - to_subtract > ret:
		# for i in range(N):
		# 	print(visited[i])
		# print("--")
		# for i in range(N):
		# 	print(my_map[i])
		# print(num_empty - to_subtract)
		# print("\n")
		ret = num_empty - to_subtract

for i in range(num_empty - 2):
	my_map[emptypos[i][0]][emptypos[i][1]] = 1
	for j in range(i + 1, num_empty - 1):
		my_map[emptypos[j][0]][emptypos[j][1]] = 1
		for k in range(j + 1, num_empty):
			my_map[emptypos[k][0]][emptypos[k][1]] = 1
			# for _ in range(N):
			# 	print(my_map[_])
			# print("\n")
			find()
			my_map[emptypos[k][0]][emptypos[k][1]] = 0
			# print(my_map[emptypos[k][0]][emptypos[k][1]])
		my_map[emptypos[j][0]][emptypos[j][1]] = 0
	my_map[emptypos[i][0]][emptypos[i][1]] = 0
ret -= 3
# for _ in range(num_empty):
# 	print(emptypos[_])
print(ret)