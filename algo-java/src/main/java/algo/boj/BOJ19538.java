package algo.boj;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ19538 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        List<List<Integer>> neighbors = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            List<Integer> input = new ArrayList<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                int neighbor = Integer.parseInt(st.nextToken());
                if (neighbor == 0) break;
                input.add(neighbor - 1);
            }
            neighbors.add(input);
        }

        int M = Integer.parseInt(br.readLine());
        int[] rumors = new int[N];
        int[] rumorsCnts = new int[N];
        Arrays.fill(rumors, -1);
        Deque<Integer> queue = new ArrayDeque<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            int rumor = Integer.parseInt(st.nextToken());
            rumors[rumor - 1] = 0;
            queue.add(rumor - 1);
        }

        while (!queue.isEmpty()) {
            int node = queue.remove();

            for (int neighbor : neighbors.get(node)) {
                rumorsCnts[neighbor]++;
                // become rumor if there are rumor neighbors over than half
                // edge case : half must be calcualted as float (2 neighbors standard != 3 neighbors standard)
                if (rumors[neighbor] == -1 && rumorsCnts[neighbor] >= (float) neighbors.get(neighbor).size() / 2) {
                    rumors[neighbor] = rumors[node] + 1;
                    queue.add(neighbor);
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if (i != 0) sb.append(" ");
            sb.append(rumors[i]);
        }
        System.out.println(sb.toString());
    }
}
