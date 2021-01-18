#!/usr/bin/env python3
import sys


def solve(N: int, C: int, a: "List[int]", b: "List[int]", c: "List[int]"):
    ss = {}
    for i in range(N):
        if a[i] - 1 in ss:
            ss[a[i] - 1] += c[i]
        else:
            ss[a[i] - 1] = c[i]
        if b[i] in ss:
            ss[b[i]] -= c[i]
        else:
            ss[b[i]] = -c[i]
    keys = list(ss.keys())
    keys.sort()
    ans = 0
    tmp = 0
    for i, k in enumerate(keys):
        if i != len(keys) - 1:
            tmp += ss[k]
            if tmp > C:
                ans += C * (keys[i + 1] - k)
            else:
                ans += tmp * (keys[i + 1] - k)
    print(ans)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    C = int(next(tokens))  # type: int
    a = [int()] * (N)  # type: "List[int]"
    b = [int()] * (N)  # type: "List[int]"
    c = [int()] * (N)  # type: "List[int]"
    for i in range(N):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
        c[i] = int(next(tokens))
    solve(N, C, a, b, c)

if __name__ == '__main__':
    main()
