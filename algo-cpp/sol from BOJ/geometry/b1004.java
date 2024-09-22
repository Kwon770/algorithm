// https://www.acmicpc.net/problem/1004
// NUMBER 1004, 어린 왕자

// 이 문제가 요구하는 최소의 탈출,진입 개수 즉, 만날 수 밖에 없는 원의 수는
// 해당 점을 포함하고 있는지의 여부로 알 수 있다는 아이디어가 핵심이다.

// 해당 점을 포함하는 원이 있는 경우 해당 원을 만나야만 한다
// 다만, 출발 도착점을 모두 포함하거나 포함하지 않은 경우는 원을 만나지 않아도 된다.

// * 문제의 조건으로 원끼리는 마주 맞닿거나 교차하지 않으며 출발 도착점은 원의 경계에 걸치는 경우가 없다고 명시했으므로
// 포함하지 않는 원에 둘러쌓이는 경우와 같은 예외적인 상황은 발생할 수 없다.

// 점을 포함하는지 여부는 원의 중심과 점의 거리가 원의 반지름보다 작은지의 여부로 판단한다.

package boj.geometry;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class b1004 {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static int t, n, x1, y1, x2, y2;
    static List<Planet> planets = new ArrayList<>();

    static class Planet {
        int x;
        int y;
        int r;

        Planet(int x, int y, int r) {
            this.x = x;
            this.y = y;
            this.r = r;
        }
    }

    public static void main(String[] args) throws IOException {
        t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int[] coor = parseIntArr(br.readLine());
            x1 = coor[0];
            y1 = coor[1];
            x2 = coor[2];
            y2 = coor[3];

            n = Integer.parseInt(br.readLine());
            planets.clear();
            for (int j = 0; j < n; j++) {
                coor = parseIntArr(br.readLine());
                planets.add(new Planet(coor[0], coor[1], coor[2]));
            }

            sol();
        }

        System.out.println(sb.toString());
    }

    static void sol() {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            double disToStart = Math.sqrt(Math.pow(planets.get(i).x - x1, 2) + Math.pow(planets.get(i).y - y1, 2));
            double disToEnd = Math.sqrt(Math.pow(planets.get(i).x - x2, 2) + Math.pow(planets.get(i).y - y2, 2));

            // (원이 두 점 모두 포함하는 경우) || (원이 두 점 모두 포함하지 않는 경우)
            if ((disToStart < planets.get(i).r && disToEnd < planets.get(i).r)
                    || (disToStart > planets.get(i).r && disToEnd > planets.get(i).r))
                continue;

            cnt++;
        }
        sb.append(cnt + "\n");
    }

    static int[] parseIntArr(String input) {
        return Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray();
    }
}