#!/usr/bin/env python3
import math

def solve(T, n, k, s):
    for t in range(T):
        N = n[t]
        K = k[t]
        S = s[t]
        _alpha = N % K
        alpha = K - _alpha
        ans = 0
        if alpha > K - alpha:
            _K = 2 * K
            ans += (N // K + 1) * 2
        else:
            _K = K
            ans += N // K + 1
        for n in range(math.ceil(math.sqrt(S))):
            if (_K - n) % alpha == 0:
                if S % n == 0:
                    ans += (N // K) * ((_K - n) // alpha)
                    print(ans)
                    return
                    # ok
    print(-1)

def main():
    T = int(input())
    N = [0] * T
    S = [0] * T
    K = [0] * T
    for i in range(T):
        N[i], S[i], K[i] = map(int, input().split())
    solve(T, N, K, S)

if __name__ == '__main__':
    main()
