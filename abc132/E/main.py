#!/usr/bin/env python3
import sys


def solve(N: int, M: int, u: "List[int]", v: "List[int]", S: int, T: int):
    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    u = [int()] * (M)  # type: "List[int]"
    v = [int()] * (M)  # type: "List[int]"
    for i in range(M):
        u[i] = int(next(tokens))
        v[i] = int(next(tokens))
    S = int(next(tokens))  # type: int
    T = int(next(tokens))  # type: int
    solve(N, M, u, v, S, T)

if __name__ == '__main__':
    main()
