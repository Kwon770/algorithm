// https://www.acmicpc.net/problem/10870
// NUMBER 10870, 피보나치 수 5

// 메모이제이션을 이용한 단순한 dp 문제이다.
// 피보나치 수의 규칙만 알면 쉽게 풀 수 있다.

package boj.dynamic_programming_2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class b10870 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] pibo = new int[21];
        pibo[1] = 1;
        pibo[2] = 1;
        pibo[3] = 2;

        int n = Integer.parseInt(br.readLine());
        for (int i = 4; i <= n; i++) {
            pibo[i] = pibo[i - 1] + pibo[i - 2];
        }

        System.out.println(pibo[n]);
    }
}