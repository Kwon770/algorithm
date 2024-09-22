// https://www.acmicpc.net/problem/1000
// 입출력과 사칙연산(5), A + B
// NUMBER 1000
package boj.warming_up;

import java.util.Scanner;

public class b1000 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b;
        a = scanner.nextInt();
        b = scanner.nextInt();
        System.out.println(a + b);
        scanner.close();
    }
}
