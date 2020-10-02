from math import sqrt
import sys
input = sys.stdin.readline
MAX = 5000001

minFactor = [i for i in range(MAX)]
for i in range(2, int(sqrt(MAX)) + 1):
    if minFactor[i] == i:
        for j in range(i * i, MAX, i):
            if minFactor[j] == j:
                minFactor[j] = i

n = int(input())
array = list(map(int, input().split()))
for k in array:
    res = ''
    while k > 1:
        res += str(minFactor[k]) + ' '
        k = k // minFactor[k]
    print(res)
