#!/usr/bin/env python3
import sys

MOD = 1000000007  # type: int


def solve(N: int, K: int, A: "List[int]"):
    ans = 0
    for i in range(len(A)):
        back = 0
        forw = 0
        num_i = A[i]
        for j in A[i + 1:]:
            if num_i > j:
                forw += 1
        for j in A[:i]:
            if num_i > j:
                back += 1
        #print(back, forw)
        ans += (forw * (K * (K + 1)) // 2 + back * ((K - 1) * K) // 2) % MOD
        ans %= MOD
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
    K = int(next(tokens))  # type: int
    A = [int(next(tokens)) for _ in range(N - 1 - 0 + 1)]  # type: "List[int]"
    solve(N, K, A)

if __name__ == '__main__':
    main()
