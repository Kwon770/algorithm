package algo.goorm.offlineChallenge23;

import java.util.Arrays;
import java.util.Scanner;

public class Day5 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] arr = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int N = arr[0];
        int K = arr[1];

        arr = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[][] nums = new int[N][2];
        for (int i = 0; i < N; i++) {
            nums[i][0] = arr[i];
            nums[i][1] = (int)(Integer.toBinaryString(arr[i]).chars().filter(c -> c == '1').count());
        }

        Arrays.sort(nums, (b, a) -> {
            if (a[1] == b[1]) {
                return a[0] - b[0];
            } else {
                return a[1] - b[1];
            }
        });

        System.out.println(nums[K - 1][0]);
    }
}
