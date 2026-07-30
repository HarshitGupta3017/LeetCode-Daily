// Solution for Minimum Number of Pushes to Type Word I in JAVA

class Solution {
    public int minimumPushes(String word) {
        // We have 8 keys (2–9), each of which can hold any number of letters.
        // The first 8 letters cost 1 push, the next 8 cost 2 pushes, and so on.
        int totalPushes = 0;

        for (int i = 0; i < word.length(); i++) {
            totalPushes += (i / 8) + 1;
        }

        return totalPushes;
    }
}
