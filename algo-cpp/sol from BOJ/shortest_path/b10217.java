// https://www.acmicpc.net/problem/10217
// NUMBER 10217, KCM Travel

// 다익스트라와 dp를 통한 길찾기 알고리즘
// 메모리 초과 상태.

package boj.shortest_path;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class b10217 {
    static class AirPlane implements Comparable<AirPlane> {
        int end;
        int cost;
        int time;

        public AirPlane(int end, int cost, int time) {
            this.end = end;
            this.cost = cost;
            this.time = time;
        }

        @Override
        public int compareTo(AirPlane airPlane) {
            // 소요 시간이 같다면 비용으로 비교
            if (this.time == airPlane.time)
                return this.cost - airPlane.cost;

            // 우선은 소요 시간으로 비교
            return this.time - airPlane.time;
        }
    }

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static final int INF = 100 * 1_000;
    static int n, m, k;
    // list[i] : i에서 출발하는 비행기 리스트
    static List<AirPlane> list[];
    // dp[i][j] = k : i노드까지 j비용으로 갈 수 있는 최소의 시간 k
    static int dp[][];

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < t; i++) {
            init();
            int result = dijkstra();
            sb.append(result == INF ? "Poor KCM\n" : result + "\n");
        }

        bw.write(sb.toString());
        bw.close();
        br.close();
    }

    private static int dijkstra() {
        PriorityQueue<AirPlane> pq = new PriorityQueue<>();
        pq.add(new AirPlane(1, 0, 0));
        dp[1][0] = 0;

        while (!pq.isEmpty()) {
            AirPlane airPlane = pq.poll();
            int node = airPlane.end;
            int cost = airPlane.cost;
            int time = airPlane.time;

            // 목적지 n에 도착했을 경우
            if (node == n)
                break;
            // 저장된 소요 시간이 이미 더 작은 경우
            if (dp[node][cost] < time)
                continue;
            dp[node][cost] = time;

            for (int i = 0; i < list[node].size(); i++) {
                AirPlane toAirPlane = list[node].get(i);
                int toNode = toAirPlane.end;
                int toCost = cost + toAirPlane.cost;
                int toTime = time + toAirPlane.time;

                // 예산보다 비싼 경우
                if (toCost > m)
                    continue;
                if (dp[toNode][toCost] < toTime)
                    continue;

                // 불필요한 push를 막기위해서 다음과 같이 값을 설정해준다.
                for (int j = toCost; j <= m; j++) {
                    if (dp[toNode][j] > toTime)
                        dp[toNode][j] = toTime;
                    pq.add(new AirPlane(toNode, toCost, toTime));
                }
            }
        }

        int result = Integer.MAX_VALUE;
        for (int i = 1; i <= m; i++) {
            result = Math.min(result, dp[n][i]);
        }
        return result;
    }

    private static void init() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        dp = new int[n + 1][m + 1];
        list = new ArrayList[n + 1];

        for (int i = 0; i <= n; i++)
            Arrays.fill(dp[i], INF);

        for (int i = 0; i <= n; i++)
            list[i] = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());
            list[start].add(new AirPlane(end, cost, time));
        }
    }
}