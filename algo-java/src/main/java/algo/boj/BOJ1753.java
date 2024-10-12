package algo.boj;

import java.util.*;

public class BOJ1753 {

    static class Node {
        int dist;
        int n;

        public Node(int dist, int n) {
            this.dist = dist;
            this.n = n;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int INF = Integer.MAX_VALUE;

        int V = sc.nextInt();
        int E = sc.nextInt();
        int K = sc.nextInt();

        Map<Integer, List<Node>> path = new HashMap<>();

        int[] distance = new int[V + 1];
        Arrays.fill(distance, INF);
        distance[K] = 0;

        boolean[] visited = new boolean[V + 1];

        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();

            List<Node> input = path.getOrDefault(u, new ArrayList<Node>());
            input.add(new Node(w, v));
            path.put(u, input);
        }

        PriorityQueue<Node> minHeap = new PriorityQueue<>((a, b) -> {
            if (a.dist == b.dist) return Integer.compare(a.n, b.n);
            else return Integer.compare(a.dist, b.dist);
        });
        minHeap.add(new Node(0, K));

        while (!minHeap.isEmpty()) {
            int node = minHeap.remove().n;
            if (visited[node]) {
                continue;
            }
            visited[node] = true;

            for (Node way : path.getOrDefault(node, Collections.emptyList())) {
                if (distance[node] + way.dist < distance[way.n]) {
                    distance[way.n] = distance[node] + way.dist;
                    minHeap.add(new Node(distance[way.n], way.n));
                }
            }
        }

        for (int i = 1; i <= V; i++) {
            if (distance[i] == INF) System.out.println("INF");
            else System.out.println(distance[i]);
        }
    }
}
