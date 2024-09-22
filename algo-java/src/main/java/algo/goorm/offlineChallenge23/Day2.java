package algo.goorm.offlineChallenge23;

import java.util.Scanner;

public class Day2 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int T = sc.nextInt();
        int M = sc.nextInt();

        int times = 0;
        for (int i = 0; i < N; i++) {
            times += sc.nextInt();
        }

        M += times;
        T += M / 60;
        T %= 24;
        M %= 60;

        System.out.print(T + " " + M);
    }
}
