#!/usr/bin/env python

a, b, c, x, y = map(int, input().split())

ans = 0

if 2 * c < (a + b):
    buy = min(x, y) * 2
    ans = buy * c
    x -= buy // 2
    y -= buy // 2
    x = max(0, x)
    y = max(0, y)

if 2 * c < a:
    buy = x * 2
    ans += buy * c
    x = 0
    y -= buy // 2
    y = max(0, y)
else:
    buy = x
    ans += buy * a
    x = 0

if 2 * c < b:
    buy = y * 2
    ans += buy * c
    y = 0
    x -= buy // 2
    x = max(0, x)
else:
    buy = y
    ans += buy * b
    y = 0

print(ans)
