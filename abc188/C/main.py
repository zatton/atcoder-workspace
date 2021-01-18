#!/usr/bin/env python3


def main():
    N = int(input())
    A = list(map(int, input().split()))

    max_ai = 0
    max_a = A[0]
    #print(A[:2 ** (N - 1)])
    for i, a in enumerate(A[:2 ** (N - 1)]):
        if max_a < a:
            max_a = a
            max_ai = i
    max_bi = 2 ** (N - 1)
    max_b = A[2 ** (N - 1)]
    for i, b in enumerate(A[2 ** (N - 1):]):
        if max_b < b:
            max_b = b
            max_bi = (2 ** (N - 1)) + i

    #print(max_ai, max_a)
    #print(max_bi, max_b)

    if max_a > max_b:
        print(max_bi + 1)
    else:
        print(max_ai + 1)

if __name__ == '__main__':
    main()
