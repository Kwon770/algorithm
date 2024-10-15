package algo.boj;

import algo.Main;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class BOJ11657 {
    static class Bus {
        int from;
        int to;
        long cost;

        Bus(int from, int to, long cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        long INF = 30000000000L;

        int N = sc.nextInt();
        long[] dist = new long[N + 1];
        Arrays.fill(dist, INF);
        dist[1] = 0;

        int M = sc.nextInt();
        List<Bus> buses = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            buses.add(new Bus(a, b, c));
        }

        for (int i = 0; i < N; i++) {
            for (Bus bus : buses) {
                if (dist[bus.from] != INF && dist[bus.to] > dist[bus.from] + bus.cost) {
                    dist[bus.to] = dist[bus.from] + bus.cost;

                    if (i == N - 1) {
                        System.out.println(-1);
                        return;
                    }
                }
            }
        }

        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) System.out.println(-1);
            else System.out.println(dist[i]);
        }
    }
}
