import sys
input = sys.stdin.readline

T = int(input())

arr = [0] * 12
arr[1] = 1
arr[2] = 2
arr[3] = 4

for i in range (4, 12):
	arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3]

for idx in range (1, T + 1):
	n = int(input())
	print(arr[n])
