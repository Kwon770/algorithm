// https://www.acmicpc.net/problem/10996
// 실습 (6), 별찍기 - 21
// NUMBER 10996
package boj.pratice;

import java.util.Scanner;

public class b10996 {
    static int n;
    static StringBuilder sb;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        sb = new StringBuilder();

        int even, odd;
        if (n % 2 == 1) {
            odd = n / 2 + 1;
            even = n / 2;
        } else {
            even = n / 2;
            odd = n / 2;
        }

        for (int i = 1; i <= (n == 1 ? 1 : n * 2); i++) {
            if (i % 2 == 1) {
                for (int j = 0; j < odd; j++) {
                    sb.append("* ");
                }
            } else {
                for (int j = 0; j < even; j++) {
                    sb.append(" *");
                }
            }
            sb.append("\n");
        }

        System.out.println(sb);
        scanner.close();
    }

    static void getStars(int i, boolean isLast) {
        for (int j = 0; j < i; j++)
            sb.append(" ");
        for (int k = 0; k < 2 * n - 1 - (i * 2); k++)
            sb.append("*");

        if (!isLast)
            sb.append("\n");
    }
}