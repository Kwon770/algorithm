package algo.goorm.offlineChallenge23;

import java.util.Arrays;
import java.util.Scanner;

public class Day4 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.nextLine());
        int[] arr = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        boolean decreased = false;
        int sum = arr[0];
        for (int i = 1; i < N; i++) {
            sum += arr[i];
            if (!decreased) {
                if (arr[i - 1] > arr[i]) {
                    decreased = true;
                }
            } else {
                if (arr[i - 1] < arr[i]) {
                    sum = 0;
                    break;
                }
            }
        }

        System.out.print(sum);
    }
}
