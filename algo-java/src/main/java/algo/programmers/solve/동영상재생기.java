package algo.programmers.solve;

import algo.Main;

import java.lang.*;
import java.util.*;

/**
 * 동영상 재생기
 * https://school.programmers.co.kr/learn/courses/30/lessons/340213?language=java
 * <p>
 *
 * 어디선가 익숙한 문제이다. 문제의 본질을 파악하지 못하면 풀수는 있지만 (문자열을 통해) 끝없는 기저조건을 체크해줘야하는 복잡한 함정에 빠진다.
 * 가장 정석은 복잡한 60진수로 분초를 계산할 필요 없이 int 초로 변환하고 시간 계산을 하는 것이다.
 * 1. compare 결과는 param1, 0, param-1 기억하기
 * 2. 배열도 스트림 사용하는 법 : Arrays.stream(arr)
 * 3. 스트림 형 변환 방법 : stream().mapToInt(Integer::parseInt) -> 원시타입 int로 변환됨 주의
 * 4. 원시타입int 배열을 래퍼클래스Integer로 변환 : arr.boxed().toArray(Integer[]::new);
 *
 * * 오프닝 뛰어넘기도 첫 시작에만 하는 것이 아니라, 오프닝 기간에 진입할때마다 해줘야 했다.
 * 문제 설명이 다양하게 해석될 수 있는 점을 늘 놓치지 말자.
 */

public class 동영상재생기 {

    public int compare(String time1, String time2) {
        int m1 = Integer.parseInt(time1.split(":")[0]);
        int s1 = Integer.parseInt(time1.split(":")[1]);
        int m2 = Integer.parseInt(time2.split(":")[0]);
        int s2 = Integer.parseInt(time2.split(":")[1]);

        if (m1 == m2) return Integer.compare(s1, s2);
        return Integer.compare(m1, m2);
    }

    public String next(String time) {
        int m = Integer.parseInt(time.split(":")[0]);
        int s = Integer.parseInt(time.split(":")[1]);

        s += 10;
        if (s >= 60) {
            m += 1;
            s -= 60;
        }

        return String.format("%02d:%02d", m, s);
    }

    public String prev(String time) {
        int m = Integer.parseInt(time.split(":")[0]);
        int s = Integer.parseInt(time.split(":")[1]);

        s -= 10;
        if (s < 0) {
            if (m <= 0) {
                m = 0;
                s = 0;
            } else {
                m -= 1;
                s += 60;
            }
        }

        return String.format("%02d:%02d", m, s);
    }

    public String solutionWithString(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";

        // op skip
        if (compare(pos, op_start) >= 0 && compare(pos, op_end) <= 0) pos = op_end;

        for (String cmd : commands) {
            if (cmd.equals("next")) {
                pos = next(pos);
                if (compare(pos, video_len) > 0) pos = video_len;

            } else if (cmd.equals("prev")) {
                pos = prev(pos);
                if (compare(pos, "00:00") < 0) pos = "00:00";
            }

            // op skip
            if (compare(pos, op_start) >= 0 && compare(pos, op_end) <= 0) pos = op_end;
        }

        return pos;
    }




    public int timeToSecond(String time) { // "mm:ss"
        Integer[] mmss = Arrays.stream(time.split(":")).mapToInt(Integer::parseInt).boxed().toArray(Integer[]::new);
        return mmss[0] * 60 + mmss[1];
    }

    public String secondToTime(int sec) {
        int m = sec / 60;
        int s = sec % 60;
        return String.format("%02d:%02d", m, s);
    }

    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        int videoLenSec = timeToSecond(video_len);
        int posSec = timeToSecond(pos);
        int opStartSec = timeToSecond(op_start);
        int opEndSec = timeToSecond(op_end);

        // op skip
        if (posSec >= opStartSec && posSec <= opEndSec) posSec = opEndSec;

        for (String cmd : commands) {
            if (cmd.equals("next")) {
                posSec = Math.min(posSec + 10, videoLenSec);

            } else if (cmd.equals("prev")) {
                posSec = Math.max(posSec - 10, 0);
            }

            if (posSec >= opStartSec && posSec <= opEndSec) posSec = opEndSec;
        }


        return secondToTime(posSec);
    }

    public static void main(String[] args) throws Exception {
        동영상재생기 main = new 동영상재생기();

        System.out.println(main.solution("34:33", "13:00", "00:55", "02:55", new String[]{"next", "prev"}));
        System.out.println(main.solution("10:55", "00:05", "00:15", "06:55", new String[]{"prev", "next", "next"}));
        System.out.println(main.solution("07:22", "04:05", "00:15", "04:07", new String[]{"next"}));
    }
}
