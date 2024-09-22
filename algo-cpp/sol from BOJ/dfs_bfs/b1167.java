// https://www.acmicpc.net/problem/1167
// NUMBER 1167, 트리의 지름

// 풀이, https://www.notion.so/sckwon770/1167-20d7d32e71eb43979ddb19b2a7b339e3

package boj.dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class b1167 {
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Node[] node;
    static boolean[] visited;
    static int n;
    static int maxDist = -1, maxNode;

    static class Node {
        int[] child;
        int[] value;

        public Node(int size) {
            this.child = new int[size];
            this.value = new int[size];
        }
    }

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());

        // Make tree
        node = new Node[n + 1];
        visited = new boolean[n + 1];
        for (int i = 0; i < n; i++) {
            int[] inp = parseIntArr(br.readLine());

            node[inp[0]] = new Node((inp.length - 2) / 2);
            int idx = 1;
            while (inp[idx] != -1) {
                node[inp[0]].child[idx / 2] = inp[idx];
                node[inp[0]].value[idx / 2] = inp[idx + 1];
                idx += 2;
            }
        }

        visited[1] = true;
        dfs(1, 0);

        Arrays.fill(visited, false);
        visited[maxNode] = true;
        dfs(maxNode, 0);

        System.out.println(maxDist);
    }

    static void dfs(int num, int dist) {
        if (maxDist < dist) {
            maxDist = dist;
            maxNode = num;
        }

        for (int i = 0; i < node[num].child.length; i++) {
            int nextNode = node[num].child[i];
            int nextValue = node[num].value[i];

            if (visited[nextNode])
                continue;

            visited[nextNode] = true;
            dfs(nextNode, dist + nextValue);
            visited[nextNode] = false;
        }
    }

    static int[] parseIntArr(String input) {
        return Arrays.stream(input.split(" ")).mapToInt(Integer::parseInt).toArray();
    }
}