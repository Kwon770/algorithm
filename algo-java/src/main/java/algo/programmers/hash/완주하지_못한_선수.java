package algo.programmers.hash;

import java.util.*;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/42576

- Map 활용
- get, put, containsKey, getOrDefault
- containsValue 가능, 대괄호 인덱싱 불가
 */

public class 완주하지_못한_선수 {
    class Solution {
        public String solution(String[] participant, String[] completion) {
            Map<String, Integer> hm = new HashMap<>();
            for (String c : completion) {
                hm.put(c, hm.getOrDefault(c, 0) + 1);
            }

            String answer = "";

            for (String p : participant) {
                if (!hm.containsKey(p) || hm.get(p) == 0) {
                    answer = p;
                    break;
                }

                hm.put(p, hm.get(p) - 1);
            }

            return answer;
        }
    }
}
