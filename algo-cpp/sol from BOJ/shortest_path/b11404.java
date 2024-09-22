// https://www.acmicpc.net/problem/11404
// NUMBER 11404, 플로이드

// 폴리이드 와샬, https://www.notion.so/sckwon770/Floyd-Warshall-2bb6020991a14c509390090f668663d7
package boj.shortest_path;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class b11404 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int[][] dist = new int[n + 1][n + 1];
        for (int[] row : dist)
            // 불가능한 경우는 int의 최댓값으로 초기화
            // 단순히 최대 가중치 10만보다 큰 수로는 최대값이 될 수 없다.
            // 1. 플로이드 와샬 과정 중에 두 개의 노선이 더해짐.
            // 2. 출력을 위한 마지막 for문에서 모든 노선이 더해지는 경우, 9,900,000 까지도 될 수 있음.
            Arrays.fill(row, Integer.MAX_VALUE);

        for (int i = 1; i <= m; i++) {
            int[] input = parseIntArr(br.readLine().split(" "));
            dist[input[0]][input[1]] = Math.min(dist[input[0]][input[1]], input[2]);
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                // Skip unnecessary stage and prevent overflow by adding with MAXVAL
                if (dist[i][k] == Integer.MAX_VALUE)
                    continue;
                for (int j = 1; j <= n; j++) {
                    // Skip unnecessary stage and prevent overflow by adding with MAXVAL
                    if (dist[k][j] == Integer.MAX_VALUE || i == j)
                        continue;

                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] == Integer.MAX_VALUE) {
                    sb.append("0 ");
                } else {
                    sb.append(dist[i][j] + " ");
                }
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }
}