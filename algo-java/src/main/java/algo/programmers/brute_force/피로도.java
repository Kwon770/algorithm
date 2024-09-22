package algo.programmers.brute_force;

/*
https://school.programmers.co.kr/learn/courses/30/lessons/87946
피로도

그르디로 풀 수 있을 것 같은 느낌이 들지만, 막상 검토해보면 그렇게 풀 수는 벗다.
가능한 경웅의 수를 모두 검토하기 위해, 순열을 만들고 계산할 수도 있지만 dfs 완탐이 가장 효율적인 것 같다.
 */

import java.util.LinkedList;
import java.util.Queue;

public class 피로도 {

        int answer = -1;
        public void dfs(int k, int[][] dungeons, boolean[] visited, int step) {
            answer = Math.max(answer, step);

            for (int i = 0; i < dungeons.length; i++) {
                if (visited[i] || k < dungeons[i][0]) {
                    continue;
                }

                visited[i] = true;
                dfs(k - dungeons[i][1], dungeons, visited, step + 1);
                visited[i] = false;
            }
        }

        Queue<Integer> queue = new LinkedList<>();

        public int solution(int k, int[][] dungeons) {
            boolean[] visited = new boolean[dungeons.length];
            dfs(k, dungeons, visited, 0);

            return answer;
        }
}
