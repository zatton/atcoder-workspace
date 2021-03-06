#!/usr/bin/env python3
import sys
import math


def solve(N: int, K: int):
    ans = 0
    for x in range(1, N + 1):
        if x > K:
            ans += 1
            continue
        cycle = math.ceil(math.log2(K/x))
        #print(x, cycle)
        ans += 1 / 2 ** cycle
    print(ans / N)
    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    K = int(next(tokens))  # type: int
    solve(N, K)

if __name__ == '__main__':
    main()
