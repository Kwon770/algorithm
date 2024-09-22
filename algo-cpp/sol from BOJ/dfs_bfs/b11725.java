// https://www.acmicpc.net/problem/11725
// NUMBER 11725, 트리의 부모 찾기

// 노드끼리 연결하여 방향성없는 트리를 만든 후, 이후에 DFS를 통해 트리의 방향성을 만든다

package boj.dfs_bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class b11725 {
    static int n;
    static Node[] nodes;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        n = Integer.parseInt(br.readLine());
        nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i);
        }

        // Make tree
        for (int i = 1; i <= n - 1; i++) {
            int[] str = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            nodes[str[0]].linkedNode.add(nodes[str[1]]);
            nodes[str[1]].linkedNode.add(nodes[str[0]]);
        }

        // Make root and Arrange Tree
        nodes[1].level = 1;
        setLevel(1, 0, 2);

        for (int i = 2; i <= n; i++) {
            sb.append(nodes[i].parent);
            sb.append('\n');
        }
        System.out.println(sb);
    }

    public static void setLevel(int curNum, int prevNum, int nextLevel) {
        for (Node node : nodes[curNum].linkedNode) {
            if (node.number == prevNum) {
                nodes[curNum].parent = prevNum;
                continue;
            }

            node.level = nextLevel;
            setLevel(node.number, curNum, nextLevel + 1);
        }
    }
}

class Node {
    public int number;
    public int level;
    public int parent;
    public List<Node> linkedNode;

    public Node(int number) {
        this.number = number;
        linkedNode = new ArrayList<>();
    }
}