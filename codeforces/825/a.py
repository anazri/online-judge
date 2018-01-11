def main():
    input()
    s = input()
    out = []
    cur = 0
    prev = '-'
    for c in s:
        if c == '0' and prev == '0':
            out.append(0)
            continue
        elif c == '0':
            out.append(cur)
            cur = 0
        else:
            cur += 1

        prev = c
    out.append(cur)
    print(''.join(str(x) for x in out))

main()
