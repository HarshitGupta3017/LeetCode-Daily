// Solution for Maximum Score From Removing Substrings in JAVA

class Solution {
    private String removeSubstr(String s, String pattern) {
        StringBuilder sb = new StringBuilder();
        for (char ch : s.toCharArray()) {
            sb.append(ch);
            int n = sb.length();
            if (n >= 2 && sb.charAt(n - 2) == pattern.charAt(0) && sb.charAt(n - 1) == pattern.charAt(1)) {
                sb.setLength(n - 2);
            }
        }
        return sb.toString();
    }

    public int maximumGain(String s, int x, int y) {
        String first = x > y ? "ab" : "ba";
        String second = x > y ? "ba" : "ab";

        String afterFirst = removeSubstr(s, first);
        int firstGain = (s.length() - afterFirst.length()) / 2 * Math.max(x, y);

        String afterSecond = removeSubstr(afterFirst, second);
        int secondGain = (afterFirst.length() - afterSecond.length()) / 2 * Math.min(x, y);

        return firstGain + secondGain;
    }
}
