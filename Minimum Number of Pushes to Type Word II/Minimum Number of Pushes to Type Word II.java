// Solution for Minimum Number of Pushes to Type Word II in JAVA

class Solution {
    public int minimumPushes(String word) {
        // Count frequency of each letter
        int[] freq = new int[26];
        for (char ch : word.toCharArray()) {
            freq[ch - 'a']++;
        }

        // Sort frequencies in ascending order
        Arrays.sort(freq);

        int totalPushes = 0;

        // Traverse from highest frequency to lowest
        for (int i = 25; i >= 0; i--) {
            int position = 25 - i; // 0, 1, 2, ...
            totalPushes += freq[i] * (position / 8 + 1);
        }

        return totalPushes;
    }
}
