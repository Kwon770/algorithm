"""
https://school.programmers.co.kr/learn/courses/30/lessons/42579
베스트앨범




"""

def solution(genres, plays):
    answer = []

    sorting = []
    genres_plays = dict()
    for g, p in zip(genres, plays):
        genres_plays[g] = genres_plays.get(g, 0) + p

    for i, (g, p) in enumerate(zip(genres, plays)):
        sorting.append((genres_plays[g], p, i, g))
    sorting.sort(key=lambda x: (-x[0], -x[1], x[2]))

    selected_genre_count = dict()
    for s in sorting:
        if selected_genre_count.get(s[3], 0) >= 2:
            continue

        selected_genre_count[s[3]] = selected_genre_count.get(s[3], 0) + 1
        answer.append(s[2])

    return answer