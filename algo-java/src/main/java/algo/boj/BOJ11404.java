package algo.boj;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ11404 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long INF = 20000000000L;
        int N = Integer.parseInt(br.readLine());
        long[][] route = new long[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                route[i][j] = INF;
                if (i == j) route[i][j] = 0;
            }
        }

        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                route[a - 1][b - 1] = Math.min(route[a - 1][b - 1], c);
            }
        }

        for (int k = 0; k < N; k++) {
            for (int a = 0; a < N; a++) {
                for (int b = 0; b < N; b++) {
                    route[a][b] = Math.min(route[a][b], route[a][k] + route[k][b]);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (i != 0) System.out.println();

            for (int j = 0; j < N; j++) {
                if(j != 0) System.out.print(" ");

                if (route[i][j] == INF) {
                    System.out.print(0);
                } else {
                    System.out.print(route[i][j]);
                }

            }
        }
    }
}
