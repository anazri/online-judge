def main():
    rows = [['***', '***', '***', '***', '***'], ['*.*', '*.*', '*..', '*.*', '*..'], ['***', '***', '*..', '*.*', '***'], ['*.*', '*.*', '*..', '*.*', '*..'], ['*.*', '***', '***', '***', '***']]

    n = int(input())
    s = input()
    for i in range(5):
        row = []
        for c in s:
            row.append(rows[i][ord(c) - ord('A')])
        print(''.join(row))

main()