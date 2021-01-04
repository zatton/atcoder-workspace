#!/usr/bin/env python3

def main():
    S = input()
    T = input()
    tl = len(T)
    sl = len(S)
    # 後ろからはめていく
    for i in reversed(range(sl - tl + 1)):
        ok = True
        for j in range(tl):
            if S[i + j] == '?' or S[i + j] == T[j]:
                continue
            ok = False
            break
        if ok:
            S = S[:i] + T + S[i + tl:]
            for k in range(sl):
                if S[k] == '?':
                    S = S[:k] + 'a' + S[k+1:]
            print(S)
            return
    print('UNRESTORABLE')

if __name__ == '__main__':
    main()
