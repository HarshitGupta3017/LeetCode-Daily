// Solution for Alternating Groups II in JAVA

class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int n = colors.length;
        int N = n + (k - 1);
        int[] newColors = new int[N];
        System.arraycopy(colors, 0, newColors, 0, n);
        for(int i = 0; i < k - 1; i++) {
            newColors[n + i] = colors[i];
        }
        int i = 0, j = 1;
        int result = 0;
        while (j < N) {
            if (newColors[j] == newColors[j - 1]) {
                i = j;
                j++;
                continue;
            }
            if (j - i + 1 == k) {
                result++;
                i++;
            }
            j++;
        }
        return result;
    }
}
