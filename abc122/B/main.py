#!/usr/bin/env python

S = input()
n = len(S)

ans = 0

for i in range(n):
    for j in range(i, n):
        #print(S[j])
        if S[j] not in ['A', 'C', 'G', 'T']:
            ans = max(j - i, ans)
            break

        if j == n - 1:
            ans = max(j - i + 1, ans)
print(ans)
