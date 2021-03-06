#!/usr/bin/env python3
import sys


def solve(N: int, K: int, a: "List[int]"):
    h = {}
    for ai in a:
        if ai in h:
            h[ai] += 1
        else:
            h[ai] = 1
    #hk.sort()
    now = K
    tmp = -1
    ans = 0
    for key in range(max(a) + 2):
    #for key in hk:
        if not key in h:
            ans += (tmp + 1) * now
            now = 0
            break
        elif h[key] < now:
            #print(key, now, (tmp + 1) * (now - h[key]))
            ans += (tmp + 1) * (now - h[key])
            now = h[key]
        tmp = key
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
    a = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, K, a)

if __name__ == '__main__':
    main()
