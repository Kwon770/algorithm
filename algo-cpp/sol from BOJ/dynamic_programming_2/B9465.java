// https://www.acmicpc.net/problem/9465
// NUMBER 9465, 스티커

// 직접 모든 경우를 계산해보되, 최대값을 유리해가면서 계산함으로써 중복 연산을 방지하는 dp를 시행한다.

package boj.dynamic_programming_2;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B9465 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());

        for (int t = 0; t < testcase; t++) {
            int n = Integer.parseInt(br.readLine());

            // dp공식의 일관성 유지를 위해,
            // 가로인 n행은 0부터 시작하며 n+1개의 공간을 만들어야 된다.
            int[][] arr = new int[n + 1][2];
            int[][] dp = new int[n + 1][2];

            for (int i = 0; i < 2; i++) {
                String[] str = br.readLine().split(" ");
                for (int j = 1; j <= n; j++) {
                    arr[j][i] = Integer.parseInt(str[j - 1]);
                }
            }

            // 최좌측 위와 아래는 무조건 포함되므로, 최좌측에서부터 위 아래를 동시에 계산한다.
            dp[1][0] = arr[1][0];
            dp[1][1] = arr[1][1];
            for (int i = 2; i <= n; i++) {
                // 다음 스티커를 고르는 경우는 대각선과 대각선의 오른쪽의 경우만 있으므로,
                // 이전의 최대인 경우인 dp[i-1][] dp[i-2][]를 비교한다.
                dp[i][0] = Math.max(dp[i - 1][1], dp[i - 2][1]) + arr[i][0];
                dp[i][1] = Math.max(dp[i - 1][0], dp[i - 2][0]) + arr[i][1];
            }
            System.out.println(Math.max(dp[n][0], dp[n][1]));
        }
    }
}