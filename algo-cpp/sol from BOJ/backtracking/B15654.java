// https://www.acmicpc.net/problem/15654
// NUMBER 15654, N과 M(5)

// dp 탐색을 백트래킹을 이용하여 수행하는 문제.
// visited boolean array를 통해 탐색여부를 확인함으로서 중복 탐색을 방지한다.

package boj.backtracking;

import java.util.Arrays;
import java.util.Scanner;

public class B15654 {
    public static int n, m;
    public static int[] arr;
    protected static int[] ans;
    protected static boolean[] visited;
    public static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n];
        ans = new int[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        dfs(0);
        System.out.println(sb);
        sc.close();
    }

    public static void dfs(int idx) {
        // End condition (Did you choose all?)
        if (idx == m) {
            for (int i = 0; i < m; i++) {
                sb.append(ans[i] + " ");
            }
            sb.append("\n");
            return;
        }

        // Explore
        for (int i = 0; i < n; i++) {
            int n = arr[i];

            // Did you visited already?
            if (visited[i])
                continue;

            visited[i] = true;
            ans[idx] = n;
            dfs(idx + 1);
            visited[i] = false;
        }
    }
}