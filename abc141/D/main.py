#!/usr/bin/env python3
import sys
import bisect
import heapq

def solve(N: int, M: int, A: "List[int]"):
    heapq.heapify(A)
    for i in range(M):
        a = heapq.heappop(A)
        a = (-1 * a) // 2
        heapq.heappush(A, -1 * a)
    ans = -1 * sum(A)
    print(ans)
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
    A = [ -1 * int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, M, A)

if __name__ == '__main__':
    main()