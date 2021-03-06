#!/usr/bin/env python3
import sys


def solve(N: int, X: int, Y: int):
    h = {}
    for i in range(1, N + 1):
        for j in range(i + 1, N + 1):
            dis = min(j - i, abs(i - X) + abs(Y - j) + 1)
            #print(i, j, dis)
            if dis in h:
                h[dis] += 1
            else:
                h[dis] = 1
    for i in range(1, N):
        if i in h:
            print(h[i])
        else:
            print(0)
    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    X = int(next(tokens))  # type: int
    Y = int(next(tokens))  # type: int
    solve(N, X, Y)

if __name__ == '__main__':
    main()
