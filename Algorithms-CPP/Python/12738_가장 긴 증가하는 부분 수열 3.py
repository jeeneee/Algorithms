from bisect import bisect_left
import sys
input = sys.stdin.readline

n = int(input())
array = list(map(int, input().split()))
lis = [array[0]]
for i in range(1, n):
    if array[i] > lis[-1]:
        lis.append(array[i])
    else:
        lis[bisect_left(lis, array[i])] = array[i]
print(len(lis))
