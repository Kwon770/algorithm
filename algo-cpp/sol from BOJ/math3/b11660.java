// https://www.acmicpc.net/problem/11660
// NUMBER 11660, 구간 합 구하기 5

// 메모이제이션을 통한 dp로 우상단을 기준으로 각 구간의 넓이 합을 사전에 구하고
// 이 구간합을 이용하여 원하는 구간합을 구한다.
// 1--------1   1--------1     1--------1     1--------1     1--------1
// 1    1   1   1        1     1      * 1     1    1   1     1  * 1   1
// 1--------1 = 1    *   1  -  1--------1  -  1    1   1  +  1--------1
// 1    1 * 1   1        1     1        1     1  * 1   1     1    1   1
// 1--------1   1--------1     1--------1     1--------1     1--------1

package boj.math3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class b11660 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] str;
        str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        int[][] arr = new int[n + 1][n + 1];
        int[][] sum = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            str = br.readLine().split(" ");
            for (int j = 1; j <= n; j++) {
                arr[i][j] = Integer.parseInt(str[j - 1]);
            }
        }

        // System.out.println();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
                // System.out.print(sum[i][j] + " ");
            }
            // System.out.println();
        }

        for (int i = 1; i <= m; i++) {
            str = br.readLine().split(" ");
            int x1 = Integer.parseInt(str[0]);
            int y1 = Integer.parseInt(str[1]);
            int x2 = Integer.parseInt(str[2]);
            int y2 = Integer.parseInt(str[3]);
            sb.append(sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
            if (i != m)
                sb.append("\n");
        }
        System.out.println(sb);
        br.close();
    }

}