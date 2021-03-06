#!/usr/bin/env python3
import sys
import math


def solve(N: int):
    ans = math.ceil(N / 1.08)
    if math.floor(ans * 1.08) == N:
        print(ans)
    else:
        print(":(")

    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    solve(N)

if __name__ == '__main__':
    main()
