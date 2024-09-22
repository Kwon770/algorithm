package algo.goorm.offlineChallenge23;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Day12 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        int[][] towns = new int[n][n];
        for (int i = 0; i < n; i++) {
            int[] town = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < n; j++) {
                towns[i][j] = town[j];
            }
        }

        int[] dr = {-1, 0, 1, 0};
        int[] dc = {0, 1, 0, -1};
        boolean[][] visited = new boolean[n][n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || towns[i][j] == 0) continue;

                count += 1;
                Queue<int[]> queue = new LinkedList<>();
                queue.add(new int[]{i, j});
                while (!queue.isEmpty()) {
                    int[] pos = queue.poll();

                    for (int k = 0; k < 4; k++) {
                        int nr = pos[0] + dr[k];
                        int nc = pos[1] + dc[k];
                        if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || towns[nr][nc] == 0) continue;

                        visited[nr][nc] = true;
                        queue.add(new int[]{nr, nc});
                    }
                }
            }
        }

        System.out.println(count);
    }
}
