indexes = dict()

def setIndexes(n, names):
    global indexes

    for i in range(n):
        indexes[names[i]] = i


def getIndexes(name):
    global indexes

    return indexes[name]


def solution(friends, gifts):
    n = len(friends)
    setIndexes(n, friends)

    scores = [0] * n
    histories = [[0 for _ in range(n)] for _ in range(n)]
    next_gifts = [0] * n

    for gift in gifts:
        a, b = gift.split()
        a_idx = getIndexes(a)
        b_idx = getIndexes(b)

        scores[a_idx] += 1
        scores[b_idx] -= 1
        histories[a_idx][b_idx] += 1

    for i in range(n):
        for j in range(i + 1, n):

            if histories[i][j] == histories[j][i]:
                if scores[i] < scores[j]: next_gifts[j] += 1
                elif scores[i] > scores[j]: next_gifts[i] += 1

            else:
                if histories[i][j] < histories[j][i]: next_gifts[j] += 1
                elif histories[i][j] > histories[j][i]: next_gifts[i] += 1

    return max(next_gifts)