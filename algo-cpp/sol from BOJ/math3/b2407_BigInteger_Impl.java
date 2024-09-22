// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// 단순한 조합 계산 문제지만, 답의 결과범위가 단순하지 않다.
// 예시로 나온 100C6은 long 범위안이지만, 100C50같은 경우 100891344545564193334812497256 으로 long 범위를 벗어난다.
// 이러한 큰 범위의 계산은 BigInteger을 사용해야한다.

// 이 코드는 BigInteger의 덧셈을 직접 구현하였다.

package boj.math3;

import java.util.Scanner;

public class b2407_BigInteger_Impl {
    static String cache[][] = new String[101][101];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        for (int i = 0; i < cache.length; i++) {
            for (int j = 0; j < cache[i].length; j++) {
                cache[i][j] = "";
            }
        }

        System.out.println(combination(n, m));
        scanner.close();
    }

    // nCr = n-1Cr + n-1Cr-1
    public static String combination(int n, int r) {
        if (n == r || r == 0)
            return "1";

        if (!cache[n][r].equals(""))
            return cache[n][r];

        cache[n][r] = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
        return cache[n][r];
    }

    public static String bigNumAdd(String num1, String num2) {
        long sum = 0;
        StringBuilder result = new StringBuilder("");

        // 1의 자리부터 더하기 사작한다
        while (!num1.isEmpty() || !num2.isEmpty() || sum != 0) {
            if (!num1.isEmpty()) {
                sum += num1.charAt(num1.length() - 1) - '0';
                num1 = num1.substring(0, num1.length() - 1);
            }
            if (!num2.isEmpty()) {
                sum += num2.charAt(num2.length() - 1) - '0';
                num2 = num2.substring(0, num2.length() - 1);
            }
            // 다시 String 형태로 만들어 append
            result.append(Long.toString(sum % 10));
            sum /= 10;
        }
        // 1의 자리부터 result에 넣었으므로 뒤집어야 한다.
        return result.reverse().toString();
    }
}