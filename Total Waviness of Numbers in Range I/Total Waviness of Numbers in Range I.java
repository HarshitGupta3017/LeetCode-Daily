// Solution for Total Waviness of Numbers in Range I in JAVA

class Solution {
    public int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int n = num1; n <= num2; n++) {
            if (n < 100) continue;

            List<Integer> d = new ArrayList<>();
            for (int t = n; t > 0; t /= 10) d.add(t % 10);

            for (int i = 1; i < d.size() - 1; i++) {
                int l = d.get(i - 1), c = d.get(i), r = d.get(i + 1);
                if ((c > l && c > r) || (c < l && c < r)) ans++;
            }
        }
        return ans;
    }
}
