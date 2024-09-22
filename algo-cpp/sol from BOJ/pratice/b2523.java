// https://www.acmicpc.net/problem/2523
// 실습 (4), 별찍기 - 13
// NUMBER 2523
package boj.pratice;

import java.util.Scanner;

public class b2523 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        StringBuilder unitSb = new StringBuilder();
        StringBuilder starsSb = new StringBuilder();
        for (int i = 1; i <= 2 * n - 1; i++) {
            if (i > n) {
                unitSb.setLength(unitSb.length() - 1);
            } else {
                unitSb.append("*");
            }
            starsSb.append(unitSb + "\n");
        }
        System.out.println(starsSb);
        scanner.close();
    }
}