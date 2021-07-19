import sys
input = sys.stdin.readline

arr = [0]
arr.append(1)
arr.append(2)
N = int(input())
for i in range (3, N + 1):
	temp = (arr[i - 1] + arr[i - 2]) % 10007
	arr.append(temp)
print(arr[N])