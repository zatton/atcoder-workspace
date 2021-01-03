#!/usr/bin/env python3
import sys
OK = "satisfiable"


def solve(N: int, S: "List[str]"):
    li = set()
    for s in S:
        if s[0] == '!':
            if s[1:] in li:
                print(s[1:])
                return
        else:
            if ('!' + s) in li:
                print(s)
                return
        li.add(s)
    print(OK)
    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    S = [next(tokens) for _ in range(N)]  # type: "List[str]"
    solve(N, S)

if __name__ == '__main__':
    main()
