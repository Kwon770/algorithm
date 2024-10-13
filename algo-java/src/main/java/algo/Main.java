package algo;

import java.lang.*;
import java.util.*;

/**
 */

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int ans = 0;
        for (int idx = 1; idx <= n; idx++) {
            int cnt = Math.min(idx, n / idx);
            ans += cnt;
        }

        System.out.println(ans);
    }
}
