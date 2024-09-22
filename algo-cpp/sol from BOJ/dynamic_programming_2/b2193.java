// https://www.acmicpc.net/problem/2193
// NUMBER 2193, 이친수

// 해당 문제는 피보나치 수열로 최적화하여 풀 수 있지만, dp의 공부를 위함이므로, dp로 풀었다.

// 1, 10, 100 101, 1000 1001 1010, 10000 10001 10010 10100 10101
// 0은 이전 숫자의 뒷자리가 0이나 1 일 때, 1은 이전 숫자의 뒷자리가 0일 때만이다.
// 따라서 마지막 숫자가 0인 숫자는 이전 숫자의 마지막이 0이나 1인 숫자의 개수,
// 마지막 숫자가 1인 숫자는 이전 숫자의 마지막이 0인 개수이다.

// X(n, 0) := X(n-1, 0) + X(n-1, 1)
// X(n, 1) := X(n-1, 0) 

package boj.dynamic_programming_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class b2193 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long[][] dp = new long[91][2];
        dp[1][0] = 0;
        dp[1][1] = 1;
        dp[2][0] = 1;
        dp[2][1] = 0;
        int n = Integer.parseInt(br.readLine());
        for (int i = 3; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }

        System.out.println(dp[n][0] + dp[n][1]);
    }
}