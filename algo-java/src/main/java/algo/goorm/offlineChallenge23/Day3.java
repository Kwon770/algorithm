package algo.goorm.offlineChallenge23;

import java.util.Scanner;

public class Day3 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int T = Integer.parseInt(sc.nextLine());
        int sum = 0;
        for (int i = 0; i < T; i++) {
            String[] arr = sc.nextLine().split(" ");
            int a = Integer.parseInt(arr[0]);
            String op = arr[1];
            int b = Integer.parseInt(arr[2]);

            if (op.equals("+"))
                sum += a + b;
            else if (op.equals("-"))
                sum += a - b;
            else if (op.equals("*"))
                sum += a * b;
            else if (op.equals("/"))
                sum += a / b;
        }

        System.out.print(sum);
    }
}
