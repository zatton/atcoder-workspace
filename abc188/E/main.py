#!/usr/bin/env python3
import math
import sys


def main():
    N, M = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    X = [0] * M
    Y = [0] * M
    for i in range(M):
        X[i], Y[i] = map(int, sys.stdin.readline().split())

    tree_next = [[] for _ in range(N)]
    root_list = set()

    for i in range(M):
        tree_next[X[i] - 1].append(Y[i] - 1)
        if (Y[i] - 1) in root_list:
            root_list.remove(Y[i] - 1)
        root_list.add(X[i] - 1)

    #print(root_list)
    # (min_buy, max_sell)

    ss = {}

    # ここ以降のsellの最大値, それ以降で買う→売る場合の利益の最大
    def calc_max(node, buy):
        if node in ss:
            return ss[node][0], max(ss[node][1], ss[node][0] - buy)

        #print(node, buy)
        if len(tree_next[node]) == 0:
            ss[node] = (A[node], A[node] - buy)
            return A[node], A[node] - buy

        max_sell = A[node]
        #print(a)
        b = max_sell - buy
        tmp_buy = min(A[node], buy)

        for child in tree_next[node]:
            ms, tmp_b = calc_max(child, tmp_buy) # 買う or スルー
            #print(child, tmp_b, tmp_buy)
            if ms > max_sell:
                max_sell = ms
            if b < tmp_b:
                b = tmp_b

        ss[node] = (max_sell, b)

        return max_sell, b


    ans = - math.inf
    for root in root_list:
        _, tmp = calc_max(root, math.inf)
        if tmp > ans:
            ans = tmp
    #print(ss)
    print(ans)

if __name__ == '__main__':
    main()
