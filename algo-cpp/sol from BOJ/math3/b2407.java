// https://www.acmicpc.net/problem/2407
// NUMBER 2407, 조합

// 단순한 조합 계산 문제지만, 답의 결과범위가 단순하지 않다.
// 예시로 나온 100C6은 long 범위안이지만, 100C50같은 경우 100891344545564193334812497256 으로 long 범위를 벗어난다.
// 이러한 큰 범위의 계산은 BigInteger을 사용해야한다.

// 이 코드는 java.math.BigInteger 라이브러리를 사용한다.

package boj.math3;

import java.math.BigInteger;
import java.util.Scanner;

public class b2407 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        if (m > n - m) {
            BigInteger a = factorial(m + 1, n);
            BigInteger b = factorial(2, n - m);
            System.out.println(a.divide(b));
        } else {
            BigInteger a = factorial(n - m + 1, n);
            BigInteger b = factorial(2, m);
            System.out.println(a.divide(b));
        }
        scanner.close();
    }

    public static BigInteger factorial(int from, int to) {
        BigInteger ans = BigInteger.ONE;
        for (int i = from; i <= to; i++) {
            ans = ans.multiply(new BigInteger(String.valueOf(i)));
        }
        return ans;
    }
}