#!/usr/bin/env python3
import sys


def solve(N: int, a: "List[int]", b: "List[int]", Q: int, t: "List[int]", e: "List[int]", x: "List[int]"):
    li = {}
    inc = {}
    dp = [() * N for _ in range(N)]
    for i in range(N):
        if a[i] in li:
            li[a[i]].add(b[i])
        else:
            li[a[i]] = {b[i]}

        if b[i] in li:
            li[b[i]].add(a[i])
        else:
            li[b[i]] = {a[i]}

        if a[i] in inc:
            _inc = inc[a[i]]
            if _inc[1] != a[i] or _inc[1] != b[i]:
                pass
            else:
                dp[_inc[0]][inc[1]].add(b[i])
                inc[b[i]].add((_inc[0], inc[1]))
        if b[i] in inc:
            _inc = inc[b[i]]
            if _inc[1] != a[i] or _inc[1] != b[i]:
                pass
            else:
                dp[_inc[0]][inc[1]].add(a[i])
                inc[a[i]].add((_inc[0], inc[1]))
    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    a = [int()] * (N - 1)  # type: "List[int]"
    b = [int()] * (N - 1)  # type: "List[int]"
    for i in range(N - 1):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
    Q = int(next(tokens))  # type: int
    t = [int()] * (Q)  # type: "List[int]"
    e = [int()] * (Q)  # type: "List[int]"
    x = [int()] * (Q)  # type: "List[int]"
    for i in range(Q):
        t[i] = int(next(tokens))
        e[i] = int(next(tokens))
        x[i] = int(next(tokens))
    solve(N, a, b, Q, t, e, x)

if __name__ == '__main__':
    main()