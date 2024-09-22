// https://www.acmicpc.net/problem/5543
// 실습(2), 상근날드
// NUMBER 5543

// 단순히 if문을 통한 비교로 구현할 수 있는 문제이다.
// 입력즉시 오름차순 정렬을 하는 TreeSet을 이용해서 풀어봤다.

package boj.pratice;

import java.util.TreeSet;
import java.util.Scanner;

public class b5543 {
    public static void main(String[] args) {
        TreeSet<Integer> bugers = new TreeSet<>();
        TreeSet<Integer> drinks = new TreeSet<>();

        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
            bugers.add(scanner.nextInt());
        }
        for (int i = 0; i < 2; i++) {
            drinks.add(scanner.nextInt());
        }
        System.out.println(bugers.first() + drinks.first() - 50);
        scanner.close();
    }
}