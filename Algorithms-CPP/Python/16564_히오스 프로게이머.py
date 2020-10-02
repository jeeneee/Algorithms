import sys
input = sys.stdin.readline
n, k = map(int, input().split())
level = [int(input()) for _ in range(n)]
level.sort()
lo = min(level)
hi = max(level) + k // n
while lo <= hi:
    mid = (lo + hi) // 2
    total = 0
    for i in level:
        if i >= mid:
            break
        total += mid - i
    if total > k:
        hi = mid - 1
    else:
        lo = mid + 1
print(hi)
