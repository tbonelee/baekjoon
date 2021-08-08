import sys
input = sys.stdin.readline

N = int(input())
S = []
for _ in range(N):
	S.append(list(map(int, input().split())))


check_board = [0] * N

ret_min = 1000000

def solve():
	global ret_min, N, S, check_board
	ptr_start = 0
	ptr_link = 0
	member_start = []
	member_link = []

	for i in range(N):
		if check_board[i] == 1:
			member_start.append(i)
		else:
			member_link.append(i)
	for i in member_start:
		for j in member_start:
			if i != j:
				ptr_start += S[i][j]
	for i in member_link:
		for j in member_link:
			if i != j:
				ptr_link += S[i][j]
	if ptr_start > ptr_link:
		diff = ptr_start - ptr_link
	else:
		diff = ptr_link - ptr_start
	if diff < ret_min:
		ret_min = diff


def fun(cnt, idx):
	global N, S, check_board
	if cnt == N / 2:
		solve()
	for i in range (idx + 1, N):
		check_board[i] = 1
		fun(cnt + 1, i)
		check_board[i] = 0

fun(0, -1)

print(ret_min)