// Solution for Delete Characters to Make Fancy String in JAVA

class Solution {
    public String makeFancyString(String s) {
        StringBuilder fancy = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            int n = fancy.length();
            if (n >= 2 && fancy.charAt(n - 1) == s.charAt(i) && fancy.charAt(n - 2) == s.charAt(i)) continue;
            fancy.append(s.charAt(i));
        }
        return fancy.toString();
    }
}
