package algo;

import java.io.*;
import java.util.*;

/**
 * 가장 큰 수
 * https://school.programmers.co.kr/learn/courses/30/lessons/42746?language=java
 * <p>
 * 풀이
 * https://way-code.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B0%80%EC%9E%A5-%ED%81%B0-%EC%88%98-%EC%BB%A4%EC%8A%A4%ED%85%80-%EC%A0%95%EB%A0%AC-%EB%AC%B8%EC%9E%90%EC%97%B4
 */

public class Main {

    public int solution(int[] arr) {
        int answer = 0;
        int INF = 1000000000 + 7;
        int sum = Arrays.stream(arr).sum();
        // 합이 홀수면, 불가능
        if (sum % 2 == 1) {
            return 0;
        }

        int target = sum / 2;
        Map<Integer, Integer> counts = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            counts.put(arr[i], counts.getOrDefault(arr[i], 0) + 1);
        }

        int left = 0;
        for (int slice = 0; slice < arr.length; slice++) {
            left += arr[slice];
            counts.put(arr[slice], counts.get(arr[slice]) - 1);

            for (int swap = -9; swap <= 9; swap++) {
                if (left - arr[slice] + swap == target) {
                    if (arr[slice] == swap) {
                        answer += 1;
                    } else {
                        answer += counts.getOrDefault(swap, 0);
                    }
                }
            }
        }

        return answer;
    }

    public static void main(String[] args) throws Exception {
        Main main = new Main();

        System.out.println(main.solution(new int[]{-1, -2, 2, 1}));
        System.out.println(main.solution(new int[]{4, 2, 4, -3, -1}));
        System.out.println(main.solution(new int[]{1, 2, 2, 1}));
//        System.out.println(main.solution(new int[]{}));
    }
}
