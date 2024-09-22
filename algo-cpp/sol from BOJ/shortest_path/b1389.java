// https://www.acmicpc.net/problem/1389
// NUMBER 1389, 케빈 베이컨의 6단계 법칙

// 플로이드 와샬을 응용한 최단거리 찾기 문제.
// 폴리이드 와샬, https://www.notion.so/sckwon770/Floyd-Warshall-2bb6020991a14c509390090f668663d7

package boj.shortest_path;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class b1389 {
    static final int MAX = 1000;
    static int n;
    static int m;
    static int[][] dist;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] input = parseIntArr(br.readLine().split(" "));
        n = input[0];
        m = input[1];

        dist = new int[n + 1][n + 1];
        for (int[] row : dist)
            Arrays.fill(row, MAX);

        for (int i = 1; i <= m; i++) {
            input = parseIntArr(br.readLine().split(" "));
            dist[input[0]][input[1]] = 1;
            dist[input[1]][input[0]] = 1;
        }

        floyd();

        printMinKevinBacon();
    }

    static void floyd() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                // Skip unnecessary stage and prevent overflow by adding with MAXVAL
                if (dist[i][k] == MAX)
                    continue;

                for (int j = 1; j <= n; j++) {
                    // Skip unnecessary stage and prevent overflow by adding with MAXVAL
                    if (dist[k][j] == MAX || i == j)
                        continue;

                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    static void printMinKevinBacon() {
        int minVal = Integer.MAX_VALUE;
        int minNum = -1;
        for (int i = 1; i <= n; i++) {
            int temp = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;

                temp += dist[i][j];
            }

            if (minVal > temp) {
                minVal = temp;
                minNum = i;
            }
        }

        System.out.println(minNum);
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }
}