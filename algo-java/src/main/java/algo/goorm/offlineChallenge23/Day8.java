package algo.goorm.offlineChallenge23;

import java.util.Arrays;
import java.util.Scanner;

public class Day8 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] nk = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int N  = nk[0];
        int K = nk[1];

        String[][] arr = new String[N][N];
        for (int i = 0; i < N; i++) {
            String[] line = sc.nextLine().split(" ");
            for (int j = 0; j < N; j++) {
                arr[i][j] = line[j];
            }
        }

        int[] dr = {0, -1, 0, 1, 0};
        int[] dc = {0, 0, 1, 0, -1};
        int[][] bombs = new int[N][N];
        for (int i = 0; i < K; i++) {
            int r = sc.nextInt() - 1;
            int c = sc.nextInt() - 1;

            for (int j = 0; j < 5; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N || arr[nr][nc].equals("#")) {
                    continue;
                }

                if (arr[nr][nc].equals("0")) {
                    bombs[nr][nc] += 1;
                } else if (arr[nr][nc].equals("@")) {
                    bombs[nr][nc] += 2;
                }
            }
        }


        int max = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                max = Math.max(max, bombs[i][j]);
            }
        }
        System.out.println(max);
    }
}
