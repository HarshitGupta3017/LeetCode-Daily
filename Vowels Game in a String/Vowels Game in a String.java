// Solution for Vowels Game in a String in JAVA

class Solution {
    public boolean doesAliceWin(String s) {
        return s.chars().anyMatch(ch -> "aeiou".indexOf(ch) >= 0);
    }
}
