#!/usr/bin/env python3
import sys


def solve(N: int, M: int, X: int, Y: int, x: "List[int]", y: "List[int]"):
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
    X = int(next(tokens))  # type: int
    Y = int(next(tokens))  # type: int
    x = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    y = [int(next(tokens)) for _ in range(M)]  # type: "List[int]"
    solve(N, M, X, Y, x, y)

if __name__ == '__main__':
    main()
