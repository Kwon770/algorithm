# https://www.acmicpc.net/problem/1991
# 1991 트리 순회
# Memory : 30860 KB / Time : 76 ms

import sys; readline = sys.stdin.readline

def f_rotate(now):
    f_way.append(convert_to_char(now))

    if tree[now][0] != -1:
        f_rotate(tree[now][0])

    if tree[now][1] != -1:
        f_rotate(tree[now][1])

def m_rotate(now):
    if tree[now][0] != -1:
        m_rotate(tree[now][0])

    m_way.append(convert_to_char(now))

    if tree[now][1] != -1:
        m_rotate(tree[now][1])


def b_rotate(now):
    if tree[now][0] != -1:
        b_rotate(tree[now][0])

    if tree[now][1] != -1:
        b_rotate(tree[now][1])

    b_way.append(convert_to_char(now))


def convert_to_num(c):
    return ord(c) - ord('A')

def convert_to_char(n):
    return chr(n + ord('A'))

def solution():
    global tree, f_way, m_way, b_way
    f_way = []
    m_way = []
    b_way = []
    N = int(input())
    tree = [[-1, -1] for _ in range(N)]
    for i in range(N):
        a, b, c = readline().split()
        if b != ".":
            tree[convert_to_num(a)][0] = convert_to_num(b)
        if c != ".":
            tree[convert_to_num(a)][1] = convert_to_num(c)

    f_rotate(0)
    print(''.join(f_way))
    m_rotate(0)
    print(''.join(m_way))
    b_rotate(0)
    print(''.join(b_way))

solution()