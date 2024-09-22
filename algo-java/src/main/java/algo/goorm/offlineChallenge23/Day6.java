package algo.goorm.offlineChallenge23;

import java.util.*;

public class Day6 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.nextLine());
        String str = sc.nextLine();

        Set<String> set = new HashSet<>();
        List<String[]> strs = new ArrayList<>();
        for (int i = 1; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                String[] arr = new String[3];
                arr[0] = str.substring(0, i);
                arr[1] = str.substring(i, j);
                arr[2] = str.substring(j, N);
                set.add(arr[0]);
                set.add(arr[1]);
                set.add(arr[2]);

                strs.add(arr);
            }
        }

        List<String> sequence = new ArrayList<>(set);
        Collections.sort(sequence);
        Map<String, Integer> score = new HashMap<>();
        for (int i = 0; i < sequence.size(); i++) {
            score.put(sequence.get(i), i + 1);
        }

        int ans = 0;
        for (String[] arr : strs) {
            int sum = score.get(arr[0]) + score.get(arr[1]) + score.get(arr[2]);
            ans = Math.max(ans, sum);
        }

        System.out.println(ans);
    }
}
