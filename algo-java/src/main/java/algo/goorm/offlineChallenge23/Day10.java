package algo.goorm.offlineChallenge23;

import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;

public class Day10 {
    static Map<Character, Integer> dr = Map.of(
            'U', -1,
            'D', 1,
            'L', 0,
            'R', 0
    );
    static Map<Character, Integer> dc = Map.of(
            'U', 0,
            'D', 0,
            'L', -1,
            'R', 1
    );

    static int N;
    static int[][] movement;
    static char[][] dir;

    public static int setPos(int a) {
        if (a == -1) return N - 1;
        if (a == N) return 0;
        return a;
    }

    public static int play(int row, int col) {
        int count = 1;
        boolean[][] visited = new boolean[N][N];
        visited[row][col] = true;

        while (true) {
            int m = movement[row][col];
            char d = dir[row][col];

            for (int i = 0; i < m; i++) {
                int nr = setPos(row + dr.get(d));
                int nc = setPos(col + dc.get(d));

                if (visited[nr][nc]) {
                    return count;
                }

                visited[nr][nc] = true;
                count += 1;
                row = nr;
                col = nc;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = Integer.parseInt(sc.nextLine());
        int[] goorm = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] player = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        movement = new int[N][N];
        dir = new char[N][N];
        for (int i = 0; i < N; i++) {
            String[] line = sc.nextLine().split(" ");
            for (int j = 0; j < N; j++) {
                int len = line[j].length();
                movement[i][j] = Integer.parseInt(line[j].substring(0, len - 1));
                dir[i][j] = line[j].charAt(len - 1);
            }
        }

        int goormScore = play(goorm[0] - 1, goorm[1] - 1);
        int playerScore = play(player[0] - 1, player[1] - 1);

        if (goormScore > playerScore) {
            System.out.println("goorm " + goormScore);
        } else {
            System.out.println("player " + playerScore);
        }
    }
}
