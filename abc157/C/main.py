#!/usr/bin/env python3
import sys


def solve(N, M, s, c):
    if N == 1:
        for i in range(10):
            ok = True
            for ss, cc in zip(s, c):
                if i != cc:
                    ok = False
                    break
            if ok:
                print(i)
                return
        print(-1)
        return
    else:
        for i in range(10 ** (N - 1), 10 ** N):
            ist = str(i)
            ok = True
            for ss, cc in zip(s, c):
                if ist[ss - 1] != str(cc):
                    #print(ist, ss, cc)
                    ok = False
                    break
            if ok:
                print(ist)
                return
        print(-1)
        return
    #for i in range(1000):
    #    sti = str(i)
    #    if len(sti) == N:
    #        ok = True
    #        for ss, cc in zip(s, c):
    #            if sti[ss - 1] != str(cc):
    #                ok = False
    #                break
    #        if ok:
    #            print(sti)
    #            return
    #print(-1)
    #return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    s = []  # type: "List[int]"
    c = []  # type: "List[int]"
    for i in range(M):
        s.append(int(next(tokens)))
        c.append(int(next(tokens)))
    solve(N, M, s, c)

if __name__ == '__main__':
    main()
