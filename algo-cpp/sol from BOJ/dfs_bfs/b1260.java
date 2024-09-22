// https://www.acmicpc.net/problem/1260
// NUMBER 1260, DFS BFS

package boj.dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class b1260 {
    static StringBuilder sb = new StringBuilder();
    static boolean[][] edges;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = input[0], m = input[1], v = input[2];
        edges = new boolean[n + 1][n + 1];
        visited = new boolean[n + 1];

        for (int i = 1; i <= m; i++) {
            input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            edges[input[0]][input[1]] = true;
            edges[input[1]][input[0]] = true;
        }

        dfs(v, n);
        sb.append("\n");
        visited = new boolean[n + 1];

        bfs(v, n);
        System.out.println(sb);
    }

    static void dfs(int v, int n) {
        visited[v] = true;
        sb.append(v + " ");
        for (int i = 1; i <= n; i++) {
            if (edges[v][i] && !visited[i])
                dfs(i, n);
        }
    }

    static void bfs(int v, int n) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(v);
        visited[v] = true;

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            sb.append(cur + " ");

            for (int i = 1; i <= n; i++) {
                if (edges[cur][i] && !visited[i]) {
                    queue.offer(i);
                    visited[i] = true;
                }
            }
        }
    }
}