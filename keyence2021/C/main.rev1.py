#!/usr/bin/env python3
import sys

MOD = 998244353  # type: int


def solve(H: int, W: int, K: int, h: "List[int]", w: "List[int]", c: "List[str]"):
    patt = [[0] * W for _ in range(H)]
    cond = {}
    for i in range(K):
        cond[(h[i] - 1, w[i] - 1)] = c[i]
    for hh in range(H):
        for ww in range(W):
            if hh == 0 and ww == 0:
                patt[hh][ww] = 1
                continue
            from_left = 0
            from_up = 0
            if ww > 0:
                if (hh, ww - 1) in cond: # 制約あり
                    if not cond[(hh, ww - 1)] == 'D':
                        from_left = 1
                else:
                    from_left = 2
            if hh > 0:
                if (hh - 1, ww) in cond: # 制約あり
                    if not cond[(hh - 1, ww)] == 'R': # 上から来れる
                        from_top = 1
                        if from_left == 0:
                            patt[hh][ww] = patt[hh - 1][ww]
                        elif from_left == 1:
                            patt[hh][ww] = patt[hh - 1][ww] + patt[hh][ww - 1]
                        else:
                            patt[hh][ww] = patt[hh - 1][ww] * 3 + patt[hh][ww - 1] * 2
                    else: # 上からは来れない
                        from_top = 0
                        if from_left == 0:
                            patt[hh][ww] = 0
                        elif from_left == 1:
                            patt[hh][ww] = patt[hh][ww - 1]
                        else:
                            patt[hh][ww] = patt[hh][ww - 1] * 2
                else: # 制約なし
                    from_top = 2
                    if from_left == 0:
                        patt[hh][ww] = patt[hh - 1][ww] * 2
                    elif from_left == 1:
                        patt[hh][ww] = patt[hh][ww - 1] * 3 + patt[hh - 1][ww] * 2
                    else:
                        patt[hh][ww] = patt[hh][ww - 1] * 6 + patt[hh - 1][ww] * 6
            else: # 上からは来れない
                from_top = 0
                if from_left == 0:
                    patt[hh][ww] = 0
                elif from_left == 1:
                    patt[hh][ww] = patt[hh][ww - 1]
                else:
                    patt[hh][ww] = patt[hh][ww - 1] * 2
            #print(hh, ww, from_left, from_top)
            #patt[hh][ww] %= MOD
    ans = patt[H - 1][W - 1]
    if not (H - 1, W - 1) in cond:
        ans *= 3
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
    H = int(next(tokens))  # type: int
    W = int(next(tokens))  # type: int
    K = int(next(tokens))  # type: int
    h = [int()] * (K)  # type: "List[int]"
    w = [int()] * (K)  # type: "List[int]"
    c = [str()] * (K)  # type: "List[str]"
    for i in range(K):
        h[i] = int(next(tokens))
        w[i] = int(next(tokens))
        c[i] = next(tokens)
    solve(H, W, K, h, w, c)

if __name__ == '__main__':
    main()