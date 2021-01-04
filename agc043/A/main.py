#!/usr/bin/env python3
import sys

def alpha(x):
    if x == '.':
        return 0
    else:
        return 1

def solve(H: int, W: int, s: "List[str]"):
    dp = [[-1] * W for _ in range(H)]
    for r in range(H):
        for c in range(W):
            now = s[r][c]
            if r == 0 and c == 0:
                dp[r][c] = alpha(now)
            elif r == 0:
                bef = s[r][c - 1]
                if (now == '#' and bef == '#') or now == '.':
                    dp[r][c] = dp[r][c - 1]
                else:
                    dp[r][c] = dp[r][c - 1] + 1
            elif c == 0:
                bef = s[r - 1][c]
                if (now == '#' and bef == '#') or now == '.':
                    dp[r][c] = dp[r - 1][c]
                else:
                    dp[r][c] = dp[r - 1][c] + 1
            else:
                if now == '.':
                    dp[r][c] = min(dp[r - 1][c], dp[r][c - 1])
                    continue

                upper = dp[r - 1][c]
                left = dp[r][c - 1]

                if s[r - 1][c] == '.':
                    upper += 1
                if s[r][c - 1] == '.':
                    left += 1

                dp[r][c] = min(upper, left)
    #print(dp)
    print(dp[-1][-1])
    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    H = int(next(tokens))  # type: int
    W = int(next(tokens))  # type: int
    s = [next(tokens) for _ in range(H)]  # type: "List[str]"
    solve(H, W, s)

if __name__ == '__main__':
    main()