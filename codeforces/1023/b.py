def solve(n, k):
    first = max(1, k - n)
    last = min(k // 2, n)

    return max(0, last - first + k % 2)

def brute(n, k):
    ans = 0
    for a in range(1, n + 1):
        b = k - a
        if a < b and b <= n:
            ans += 1

    return ans

# a < k - a
# 2a < k
# a < n
# k - a <= n
# k - n <= a

# (1, k - 1), (2, k - 2), ... (k / 2, k / 2)
n, k = map(int, input().split())
print(solve(n, k))
