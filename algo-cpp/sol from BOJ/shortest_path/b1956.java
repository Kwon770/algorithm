// https://www.acmicpc.net/problem/1956
// NUMBER 1956, 운동

// 플로이드 와샬 알고리즘을 활용하는 문제이다.
// 플로이드 와샬 알고리즘은 모든 최단 경로를 구하므로,
// 이 문제에서 요구하는 최소 거리의 사이클을 구하는 코드를 단순하게 해준다.

// 그 이유는 플로이드 와샬의 원리를 알면 이해할 수 있는데,
// 이 알고리즘은 모든 중간 정점을 확인하며 모든 최단 경로를 찾는다.
// 즉, 이 알고리즘을 통해 찾는 최단거리 배열을 활용하면 여러 점을 거치는 최단거리를 확인할 필요가 없다.

// 예를 들어, A -> B -> C -> A 가 최소 사이클일 경우,
// A -> B -> C가 A -> C의 최단 경로일 것이다.
// 따라서 distance[A][B] + distance[B][C] 할 필요 없이 distance[A][C] 를 찾으면 된다.
// (distance[A][B] + distance[B][C]가 최소 경로이므로, 플로이드 와샬 알고리즘이 이미 이 값을 distance[A][C]에 갱신했다.)

// 따라서 distance[i][j] + distance[j][i] 의 최소값을 구하면 최소 사이클이다.

package boj.shortest_path;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class b1956 {
    static int v;
    static int e;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] input = parseIntArr(br.readLine());
        v = input[0];
        e = input[1];

        dist = new int[v + 1][v + 1];
        for (int[] arr : dist)
            Arrays.fill(arr, Integer.MAX_VALUE);

        for (int i = 0; i < e; i++) {
            input = parseIntArr(br.readLine());
            dist[input[0]][input[1]] = input[2];
        }

        floyd();

        System.out.println(returnMinCycle());
    }

    static void floyd() {
        for (int k = 1; k <= v; k++) {
            for (int i = 1; i <= v; i++) {
                // if: i == k || i -/-> k
                if (dist[i][k] == Integer.MAX_VALUE)
                    continue;

                for (int j = 1; j <= v; j++) {
                    // if: i == j || k == j || k -/-> j
                    if (i == j || dist[k][j] == Integer.MAX_VALUE)
                        continue;

                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }

            }
        }
    }

    static int returnMinCycle() {
        int cycle = Integer.MAX_VALUE;
        for (int i = 1; i <= v; i++) {
            // j will start from (i + 1) to avoid overlap loop
            for (int j = i + 1; j <= v; j++) {
                // if: i == j || i -/-> j || j -/-> i
                if (dist[i][j] == Integer.MAX_VALUE || dist[j][i] == Integer.MAX_VALUE)
                    continue;

                cycle = Math.min(cycle, dist[i][j] + dist[j][i]);
            }
        }

        return cycle == Integer.MAX_VALUE ? -1 : cycle;
    }

    static int[] parseIntArr(String input) {
        return Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray();
    }
}