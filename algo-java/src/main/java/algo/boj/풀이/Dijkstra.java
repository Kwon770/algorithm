package algo.boj.풀이;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/*
    1916. 최소비용 구하기
    https://www.acmicpc.net/problem/1916
    Memeory: 88356 KB, Time: 908 ms

    기본적인 다익스트라 알고리즘 문제이다. 다음을 가져가자.

    [다익스트라]
    1. 우선순위 큐를 사용하라: 일반 큐와 시간복잡도 차이가 크므로, 무조건 우선순위 큐로 구현
    2. 그래프의 크기와 간선의 개수를 주의해라: 간선은 2차원 배열에 표현하는 것이 간단하고 쉽다.
    단, 간선의 갯수가 엄청난 경우, 인접행렬로 관리해아 할 것이다.

    [자바]
    1. 우선순위 큐에 배열 넣기: 배열을 넣을 땐, 비교자를 무조건 재정의해야 함. 람다 함수 사용 + Integer.compare (기본 오름차순)
    2. 배열 입력과 변환
    int[] ab = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    Integer[] qq = Arrays.stream(br.readLine().split(" ")).map(Integer::parseInt).toArray(Integer[]::new);
 */

public class Dijkstra {
    static void dijkstra() {
        distances = new int[N];
        Arrays.fill(distances, Integer.MAX_VALUE);

        PriorityQueue<Integer[]> queue = new PriorityQueue<>((Integer[] a, Integer[] b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }

            return Integer.compare(a[0], b[0]);
        });
        queue.add(new Integer[]{0, a});

        while (!queue.isEmpty()) {
            Integer[] poll = queue.poll();
            int dist = poll[0];
            int now = poll[1];

            if (dist > distances[now]) continue;
            for (Integer[] bus : buses[now]) {
                int cost = dist + bus[1];
                if (cost < distances[bus[0]]) {
                    distances[bus[0]] = cost;
                    queue.add(new Integer[]{cost, bus[0]});
                }
            }
        }
    }

    static int N, M;
    static List<Integer[]>[] buses;
    static int[] distances;
    static int a, b;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        buses = new List[N];
        for (int i = 0; i < N; i++) {
            buses[i] = new ArrayList<>();
        }

        for (int i = 0; i < M; i++) {
            int[] bus = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            buses[bus[0] - 1].add(new Integer[]{bus[1] - 1, bus[2]});
        }
        int[] ab = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        a = ab[0] - 1;
        b = ab[1] - 1;

        dijkstra();
        System.out.println(distances[b]);
    }
}
