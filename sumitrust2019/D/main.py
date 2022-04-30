#!/usr/bin/env python

N = int(input())
S = input()

ans = 0

for i in range(1000):
    key = ('000'+str(i))[-3:]
    #print(key)

    pos = 0
    for s in S:
        if s == key[pos]:
            pos += 1
            if pos == 3:
                ans += 1
                break

    #istr = str(i)
    #istr = istr.zfill(3)
    #cnt = 0
    #for s in S:
    #    if s == istr[cnt]:
    #        cnt += 1
    #        if cnt == 3:
    #            ans += 1
    #            break

print(ans)
