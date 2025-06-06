// Solution for Using a Robot to Print the Lexicographically Smallest String in JAVA

class Solution {
    public String robotWithString(String s) {
        int n = s.length();

        // Step 1: Compute the minimum character to the right (including self) for each index
        char[] minRight = new char[n];
        minRight[n - 1] = s.charAt(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            minRight[i] = (char) Math.min(s.charAt(i), minRight[i + 1]);
        }

        StringBuilder robotBuffer = new StringBuilder(); // string t held by the robot
        StringBuilder paper = new StringBuilder();       // final written string

        for (int i = 0; i < n; ++i) {
            robotBuffer.append(s.charAt(i)); // Operation 1: move from s to t

            char smallestRemaining = (i + 1 < n) ? minRight[i + 1] : s.charAt(i);

            // Operation 2: write from t to paper if last char in t <= smallestRemaining
            while (robotBuffer.length() > 0 && robotBuffer.charAt(robotBuffer.length() - 1) <= smallestRemaining) {
                paper.append(robotBuffer.charAt(robotBuffer.length() - 1));
                robotBuffer.deleteCharAt(robotBuffer.length() - 1);
            }
        }

        // Flush remaining characters from t to paper
        while (robotBuffer.length() > 0) {
            paper.append(robotBuffer.charAt(robotBuffer.length() - 1));
            robotBuffer.deleteCharAt(robotBuffer.length() - 1);
        }

        return paper.toString();
    }
}
