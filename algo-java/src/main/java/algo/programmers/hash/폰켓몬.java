package algo.programmers.hash;

import java.io.*;
import java.util.*;

/*
* https://school.programmers.co.kr/learn/courses/30/lessons/1845
*
* - Set 활용법
* - int[] -> Set 변환
* */

public class 폰켓몬 {

    class Solution {
        public int solution(int[] nums) {
            Set<Integer> hs = new HashSet();

            for (int num : nums) hs.add(num);

            return Math.min(hs.size(), nums.length / 2);
        }
    }
}
