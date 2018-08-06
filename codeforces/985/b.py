def main():
    n, m = map(int, input().split())
    grid = [input() for _ in range(n)]
    counts = [sum(grid[i][j] == '1' for i in range(n)) for j in range(m)]
    no_skip = all(any(grid[i][j] == '1' and counts[j] == 1 for j in range(m)) for i in range(n))

    print('NO' if no_skip else 'YES')
main()
