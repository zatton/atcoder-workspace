#!/usr/bin/env python3
import copy
import numpy as np

def solve(H, W, A):
    ans = copy.copy(A)
    #print(np.all(A[0, :] == '.'))
    d_rows = 0
    for i in range(H):
        if np.all(A[i, :] == '.'):
            ans = np.vstack((ans[:i-d_rows, :], ans[i-d_rows+1:, :]))
            d_rows += 1
    d_cols = 0
    for j in range(W):
        #print(ans)
        if np.all(A[:, j] == '.'):
            ans = np.hstack((ans[:, :j-d_cols], ans[:, j-d_cols+1:]))
            d_cols += 1
    for a in ans:
        print("".join(map(str, a)))

def main():
    H, W = map(int, input().split())
    A = np.array([list(input()) for _ in range(H)])
    solve(H, W, A)
    pass

if __name__ == '__main__':
    main()
