// Solution for Find the Original Typed String I in JAVA

class Solution {
    public int possibleStringCount(String word) {
        int repeatCount = 0;
        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                repeatCount++;
            }
        }
        return repeatCount + 1;
    }
}
