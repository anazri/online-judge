def covers(n, a, num, den):
    # a[i] = num / den * i + a[0]
    # den * (a[i] - a[0]) = num * i

    start = a[0]
    used = [False] * n
    used[0] = True

    for i in range(1, n):
        if den * (a[i] - a[0]) == num * i:
            used[i] = True

    first_unused = -1
    for i in range(n):
        if not used[i]:
            first_unused = i
            break

    if first_unused == -1:
        return False

    for i in range(n):
        if used[i]:
            continue

        if den * (a[i] - a[first_unused]) == num * (i - first_unused):
            used[i] = True

    return all(used)

def main():
    n = int(input())
    a = list(map(int, input().split()))

    if n < 2:
        print('No')
    elif n == 2:
        print('Yes')
    else:
        diffs = set(a[i] - a[i - 1] for i in range(2, n))
        d = list(diffs)[0]
        solved = (len(diffs) == 1 and a[1] - a[0] != d)
        for i in range(1, n):
            if covers(n, a, a[i] - a[0], i):
                solved = True
                break

        print('Yes' if solved else 'No')

main()
