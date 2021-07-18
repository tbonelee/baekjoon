import math
import sys
input = sys.stdin.readline

arr = [0] * 50001
N = int(input())
arr[1] = 1
# print(int(math.sqrt(N)))
for i in range (2, N + 1):
	arr[i] = arr[i - 1] + 1
	for j in range (1, int(math.sqrt(i))+1):

		# if j * j > i:
		# 	break
		if arr[i] > arr[i - j * j] + 1:
			# print(i, j)
			arr[i] = arr[i - j *  j] + 1
print(arr[N])