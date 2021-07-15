import sys
input = sys.stdin.readline

N,M = map(int, input().split())
arr = [0]
dic = dict()
for i in range(1, N+1):
	temp = input()
	arr.append(temp)
	dic[temp] = i
for j in range(1, M+1):
	tmp = input()
	if tmp.isalpha():
		print(dic[tmp])
	else :
		print(arr[int(tmp)])