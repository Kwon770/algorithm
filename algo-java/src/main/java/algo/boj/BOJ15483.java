package algo.boj;

import java.util.Scanner;

public class BOJ15483 {
    public void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String source = sc.nextLine();
        String target = sc.nextLine();

        int maxLen = Math.max(source.length(), target.length());
        int[][] lcs = new int[maxLen + 1][maxLen + 1];

        for (int i = 0; i <= source.length(); i++) {
            for (int j = 0; j <= target.length(); j++) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = Math.max(i, j);
                    continue;
                }

                if (source.charAt(i - 1) == target.charAt(j - 1)) {
                    lcs[i][j] = lcs[i - 1][j - 1] ;
                } else {
                    int minLastLcs = Math.min(lcs[i - 1][j], lcs[i][j - 1]);
                    minLastLcs = Math.min(minLastLcs, lcs[i - 1][j - 1]);
                    lcs[i][j] = minLastLcs + 1;
                }
            }
        }

        System.out.println(lcs[source.length()][target.length()]);
    }
}
