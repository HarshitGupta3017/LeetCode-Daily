// Solution for Shortest and Lexicographically Smallest Beautiful String in JAVA

class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int left = 0;
        int ones = 0;
        String best = "";

        for (int right = 0; right < s.length(); right++) {

            if (s.charAt(right) == '1') {
                ones++;
            }

            // More than k ones -> move left
            while (ones > k) {
                if (s.charAt(left) == '1') {
                    ones--;
                }
                left++;
            }

            // Remove leading zeros
            while (left <= right && s.charAt(left) == '0') {
                left++;
            }

            // Exactly k ones
            if (ones == k) {
                String candidate = s.substring(left, right + 1);

                if (best.isEmpty()
                        || candidate.length() < best.length()
                        || (candidate.length() == best.length()
                            && candidate.compareTo(best) < 0)) {
                    best = candidate;
                }
            }
        }

        return best;
    }
}
