package algo.programmers.sort;

import java.util.Arrays;

/**
 * 가장 큰 수
 * https://school.programmers.co.kr/learn/courses/30/lessons/42746?language=java
 *
 * 풀이
 * https://way-code.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B0%80%EC%9E%A5-%ED%81%B0-%EC%88%98-%EC%BB%A4%EC%8A%A4%ED%85%80-%EC%A0%95%EB%A0%AC-%EB%AC%B8%EC%9E%90%EC%97%B4
 */

public class 가장_큰_수 {

    public String solution(int[] numbers) {
        String answer = "";
        String[] strings = new String[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            strings[i] = String.valueOf(numbers[i]);
        }

        Arrays.sort(strings, (s1, s2) -> (s2 + s1).compareTo(s1 + s2));

        if (strings[0].startsWith("0")) return "0";
        for (String s : strings) {
            answer += s;
        }
        return answer;
    }
}
