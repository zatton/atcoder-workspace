#!/usr/bin/env python3
import sys


def solve(AtCoder: str, s: str, Contest: str):
    return


# Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    AtCoder = next(tokens)  # type: str
    s = next(tokens)  # type: str
    Contest = next(tokens)  # type: str
    solve(AtCoder, s, Contest)

if __name__ == '__main__':
    main()
