// https://www.acmicpc.net/problem/7562
// NUMBER 7562, 나이트의 이동

// 나이트의 이동은 올곧지 않으므로, 그 움직임의 규칙을 통해 최단거리를 파악하기 힘들다.
// 따라서 완전 탐색을 통하여 풀어야 하는데, 움직임의 정확한 규칙을 모른채 dfs를 통해 풀기엔 어려움이 있으므로
// bfs를 통하여 푼다.

// 나이트의 여러가지 움직임을 쉽게 계산하고, 이전 위치를 쉽게 파악하기 위해 움직임 점을 배열로 저장한다.
// 시작점과 도착점이 같은 경우는, bfs 탐색 알고리즘에서 파악하지 못하는 취약점임으로, 따로 확인해줘야된다.

package boj.dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class b7562 {
    static StringBuilder sb = new StringBuilder();
    static int size;
    static int[] iMove = { 1, 2, 2, 1, -1, -2, -2, -1 };
    static int[] jMove = { -2, -1, 1, 2, 2, 1, -1, -2 };
    static boolean[][] visited;
    static Queue<int[]> queue;
    static int[] target;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        for (int k = 0; k < t; k++) {
            size = Integer.parseInt(br.readLine());
            int[] temp = parseIntArr(br.readLine().split(" "));
            int[] start = { temp[0], temp[1], 0, -1 };
            target = parseIntArr(br.readLine().split(" "));

            if (start[0] == target[0] && start[1] == target[1]) {
                sb.append(0 + "\n");
            }

            visited = new boolean[300][300];
            visited[start[0]][start[1]] = true;
            queue = new LinkedList<>();
            queue.offer(start);
            bfs();
        }

        System.out.println(sb);
    }

    static void bfs() {
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int p = 0; p < 8; p++) {
                if (p == cur[3])
                    continue;

                int iNext = cur[0] + iMove[p];
                int jNext = cur[1] + jMove[p];

                if (iNext == target[0] && jNext == target[1]) {
                    sb.append(cur[2] + 1 + "\n");
                    return;
                }

                if (iNext >= 0 && iNext < size && jNext >= 0 && jNext < size && !visited[iNext][jNext]) {
                    queue.offer(new int[] { iNext, jNext, cur[2] + 1, p > 3 ? p - 4 : p + 4 });
                    visited[iNext][jNext] = true;
                }
            }
        }
    }

    static int[] parseIntArr(String[] strArr) {
        return Arrays.stream(strArr).mapToInt(Integer::parseInt).toArray();
    }
}