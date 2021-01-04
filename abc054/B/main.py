#!/usr/bin/env python3
import sys

YES = "Yes"  # type: str
NO = "No"  # type: str


def solve(N: int, M: int, A: "List[str]", B: "List[str]"):
    s = set()
    for i in range(N - M + 1):
        for j in range(N - M + 1):
            st = ''
            for ii in range(M):
                st += A[i + ii][j:j + M]
            s.add(st)
    tmp = ''
    for i in range(M):
        tmp += B[i]

    #print(s)
    #print(tmp)

    if tmp in s:
        print(YES)
    else:
        print(NO)
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
    A = [next(tokens) for _ in range(N)]  # type: "List[str]"
    B = [next(tokens) for _ in range(M)]  # type: "List[str]"
    solve(N, M, A, B)

if __name__ == '__main__':
    main()
