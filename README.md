# 🧑‍💻 알고리즘 공부 노트

- 그래프 탐색의 엣지케이스를 조심하자...

그래프 탐색의 최적화하려다가 엣지케이스에 걸리는 경우를 조심하자 => 쓸데없이 최적화하지말고 푸는 것에 집중하자 ([puyopuyo](http://noj.am/11559))


<br/>
<br/>

---

# 📚 문제 아카이브

| note                                                            | link                                                      |
|-----------------------------------------------------------------|-----------------------------------------------------------|
| <span style="background-color: #fff5b1;">**점검하고 가자**</span>     |                                                           |
| Graph - MST(Minimum Spanning Tree, 최소신장트리) - 크루스칼, 프림           | [도시 분할 계획](./sol_from_BOJ/graph/boj1647.py)               |
|                                                                 |                                                           |
|                                                                 |                                                           |
| <span style='background-color: #fff5b1'>**DP**</span>           |                                                           |
| DP 전형적인 유형 (표 형태)                                               | [동물원](./sol_from_BOJ/dp/boj1309.py)                       |
| DP 전형적인 유형 : 캐싱이 없으면 고려해야할 경우의 수가 너무 많은 문제 (표 형태)               | [금광](./sol_from_etc/book_이것이코딩테스트다/Q31.py)                |
| DP 전형적인 유형 : 입력에 따라 변하는 조건때문에 그리디는 안되고, 탐색은 시간초과날 경우            | [팩스](./sol_from_BOJ/dp/boj2341.py)                        |
| DP 냄새가 옅어도 파이썬에선 잘 캐치해야한다.                                      | [파이프 이동1](./sol_from_BOJ/dp/boj17070.py)                  |
| DP 문제처럼 보여도 그리디로 풀 수 있는 문제는?                                    | [택배](./sol_from_BOJ/greedy/boj8980.py)                    |
| DP 문제처럼 보여도 메모리가 모자라다면 타개법을 찾아야하는 문제는?                          | [신기한 소수](./sol_from_BOJ/ps/boj2023.py)                    |
|                                                                 |                                                           |
|                                                                 |                                                           |
| <span style="background-color: #fff5b1;">**PS**</span>          |                                                           |
| 원소가 두 개인 튜플 탐색                                                  | [뱀](./sol_from_BOJ/simulation/boj3190.py)                 |
| 정렬 조건 설정하기, 조건 설정 방법별 소요 시간 차이                                  | [국영수](./sol_from_BOJ/sort/boj10825.py)                    |
| itertools.combinations 활용해서 감소하는 수 만들기 : 조합은 주어진 배열 순서대로        | [감소하는 수](./sol_from_BOJ/ps/boj1038.py)                    |
| 이진 탐색 응용 (범위 내의 원소 갯수 구하기, 문자열의 일정 범위 검색)                       | [가사 검색](./sol_from_Programmers/kakao_blind/pr60060.py)    |
| 원소 변경이 잦은 배열의 중앙값 찾기 : MaxHeap, MinHeap 응용                      | [중앙값 구하기](./sol_from_BOJ/data_structure/boj2696.py)       |
| 프로그래밍적인 풀이가 오하려 복잡할 때는 파이써닉하게 짜보자1 (조건비교, 패턴)                   | [TicTaeToe](./sol_from_BOJ/ps/boj13227.py)                |
| 위상정렬(그래프의 노드간의 의존관계 처리 로직) 혹은 재귀+DP 풀이                          | [ACM Craft](./sol_from_BOJ/ps/boj1005.py)                 |
|                                                                 |                                                           |
|                                                                 |                                                           |
| <span style="background-color: #fff5b1;">**Simulation**</span>  |                                                           |
| 배열을 90도 회전시키기                                                   | [자물쇠와 열쇠](./sol_from_Programmers/kakao_blind/pr60059.py)  |
| 좌표 기준이 칸인지 점인지 주의하기                                             | [영역 구하기](./sol_from_BOJ/DFSBFS/boj2583.py)                |
|                                                                 |                                                           |
|                                                                 |                                                           |
| <span style="background-color: #fff5b1;">**Two Pointer**</span> |                                                           |
| 투포인터를 써야한다는 것을 눈치채야하는 문제                                        | [Longest Strike](./sol_from_codeforces/790_div4/1676F.py) |
| 투포인터로 부분합 구하기                                                   | [부분합](./sol_from_BOJ/two_pointer/boj1806.py)              |