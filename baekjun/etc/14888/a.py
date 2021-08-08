import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
num_oper = list(map(int, input().split()))

# print("N = ", N)
# print("A = ", A)
# print ("num_oper = ", num_oper)

A_len = len(A)

min_ret = 10000000000
max_ret = -10000000000

oper_tmp = []

def fun(idx, ret, num_add, num_sub, num_mult, num_div):
	global A, A_len, min_ret, max_ret
	if idx == A_len:
		if ret < min_ret:
			min_ret = ret
		if ret > max_ret:
			max_ret = ret
		return
	if num_add > 0:
		fun(idx + 1, ret + A[idx], num_add - 1, num_sub, num_mult, num_div)
	if num_sub > 0:
		fun(idx + 1, ret - A[idx], num_add, num_sub - 1, num_mult, num_div)
	if num_mult > 0:
		fun(idx + 1, ret * A[idx], num_add, num_sub, num_mult - 1, num_div)
	if num_div > 0 and A[idx] != 0:
		if ret >= 0:
			fun(idx + 1, ret // A[idx], num_add, num_sub, num_mult, num_div - 1)
		else:
			fun(idx + 1, -((-ret) // A[idx]), num_add, num_sub, num_mult, num_div - 1)

fun(1, A[0], num_oper[0], num_oper[1], num_oper[2], num_oper[3])

print(max_ret)
print(min_ret)


# print(N)