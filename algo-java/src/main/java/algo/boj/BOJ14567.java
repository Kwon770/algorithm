package algo.boj;

import java.util.*;

/**
 * https://www.acmicpc.net/problem/14567
 * 선수과목 (Prerequisite)
 *
 * 위상정렬 추천 문제인만큼, 위상정렬을 알고 있으면 약간의 응용이 필요하지만 명확히 풀 수 있는 문제였다.
 *
 * 1. 각각의 수업을 몇 번째 학기 때 들었는지를 기록하기 위해, 큐를 이용한 위상정렬의 스탭을 분리하기 위해 thisSemester, nextSemester를 분리해서 풀었다.
 * 2. 최적화를 위해 1개의 큐로 줄이기 위해, Lecture 클래스를 도입해 큐에 Lecture를 넣는 순간 몇 번째 학기에 수강하는지 기록할 수 있게 했다.
 *
 */
public class BOJ14567 {
    public static class Lecture {
        int number;
        int semester;
        public Lecture(int number, int semester) {
            this.number = number;
            this.semester = semester;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[][] conditions = new int[N + 1][N + 1];
        int[] preConditions = new int[N + 1];

        for (int i = 0; i < M; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();

            conditions[from][to] = 1;
            preConditions[to]++;
        }

        Deque<Lecture> q = new ArrayDeque<>();
        Integer[] ans = new Integer[N + 1];
        for (int i = 1; i <= N; i++) {
            if (preConditions[i] == 0) q.add(new Lecture(i, 1));
        }

        while (!q.isEmpty()) {
            Lecture lecture = q.remove();
            ans[lecture.number] = lecture.semester;

            for (int i = 1; i <= N; i++) {
                if (conditions[lecture.number][i] != 1) continue;

                preConditions[i]--;
                if (preConditions[i] == 0) q.add(new Lecture(i, lecture.semester + 1));
            }
        }

        for (int i = 1; i <= N; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}
