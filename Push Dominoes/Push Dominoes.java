// Solution for Push Dominoes in JAVA

class Solution {
    public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        int[] rightClosestL = new int[n];
        int[] leftClosestR = new int[n];
        // Fill leftClosestR (closest R to the left)
        for (int i = 0; i < n; i++) {
            if (dominoes.charAt(i) == 'R') {
                leftClosestR[i] = i;
            } else if (dominoes.charAt(i) == '.') {
                leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
            } else {
                leftClosestR[i] = -1;
            }
        }
        // Fill rightClosestL (closest L to the right)
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes.charAt(i) == 'L') {
                rightClosestL[i] = i;
            } else if (dominoes.charAt(i) == '.') {
                rightClosestL[i] = i < n - 1 ? rightClosestL[i + 1] : -1;
            } else {
                rightClosestL[i] = -1;
            }
        }
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int distRightL = Math.abs(i - rightClosestL[i]);
            int distLeftR = Math.abs(i - leftClosestR[i]);
            if (leftClosestR[i] == rightClosestL[i]) {
                result.append('.');
            } else if (leftClosestR[i] == -1) {
                result.append('L');
            } else if (rightClosestL[i] == -1) {
                result.append('R');
            } else if (distRightL == distLeftR) {
                result.append('.');
            } else {
                result.append(distRightL < distLeftR ? 'L' : 'R');
            }
        }
        return result.toString();
    }
}
