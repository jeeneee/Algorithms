from math import factorial


def nCr(n, r):
    return factorial(n) // (factorial(r) * factorial(n-r))


n = int(input())
if n < 9:
    print(0)
else:
    print(nCr(n//3-1, 2))
