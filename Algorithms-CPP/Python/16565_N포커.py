from math import factorial


def nCr(n, r):
    return factorial(n) // (factorial(n-r) * factorial(r))


n = int(input())
ans = 0
temp = 1
for i in range(4, n+1, 4):
    ans += temp * nCr(13, i // 4) * nCr(52 - i, n - i)
    temp *= -1
print(ans % 10007)
