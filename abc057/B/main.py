#!/usr/bin/env python3
import sys
import math


def solve(N: int, M: int, a: "List[int]", b: "List[int]", c: "List[int]", d: "List[int]"):
    for student in zip(a, b):
        nearest_idx = None
        nearest_d = math.inf
        for idx, point in enumerate(zip(c, d)):
            dis = abs(student[0] - point[0]) + abs(student[1] - point[1])
            if dis < nearest_d:
                nearest_d = dis
                nearest_idx = idx
        print(nearest_idx + 1)
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
    a = [int()] * (N)  # type: "List[int]"
    b = [int()] * (N)  # type: "List[int]"
    for i in range(N):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
    c = [int()] * (M)  # type: "List[int]"
    d = [int()] * (M)  # type: "List[int]"
    for i in range(M):
        c[i] = int(next(tokens))
        d[i] = int(next(tokens))
    solve(N, M, a, b, c, d)

if __name__ == '__main__':
    main()
