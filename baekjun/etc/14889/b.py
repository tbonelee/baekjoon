import sys
input = sys.stdin.readline

N = int(input())
S = []
for _ in range(N):
	S.append(list(map(int, input().split())))


my_start = []

ret_min = 1000000

def solve():
	global ret_min, N, S
	ptr_start = 0
	ptr_link = 0
	my_link = []

	for i in range(0, N // 2 - 1):
		for j in range(i + 1, N // 2):
			ptr_start += S[my_start[i]][my_start[j]] + S[my_start[j]][my_start[i]]
	check_board = [0] * N
	for i in my_start:
		check_board[i] = 1
	for i in range(0, N):
		if check_board[i] == 0:
			my_link.append(i)

	for i in range(0, N // 2 - 1):
		for j in range(i + 1, N // 2):
			ptr_link += S[my_link[i]][my_link[j]] + S[my_link[j]][my_link[i]]

	if ptr_start > ptr_link:
		diff = ptr_start - ptr_link
	else:
		diff = ptr_link - ptr_start
	if diff < ret_min:
		ret_min = diff


def fun(idx):
	global N, S
	if idx == N:
		return
	if len(my_start) == N / 2:
		solve()
		return

	my_start.append(idx)
	fun(idx + 1)
	my_start.pop(len(my_start) - 1)
	fun(idx + 1)

fun(0)

print(ret_min)