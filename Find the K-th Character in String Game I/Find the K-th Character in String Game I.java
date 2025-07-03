// Solution for Find the K-th Character in String Game I in JAVA

class Solution {
    public char kthCharacter(int k) {
        StringBuilder word = new StringBuilder("a");
        while (word.length() < k) {
            StringBuilder temp = new StringBuilder();
            for (int i = 0; i < word.length(); i++) {
                char ch = word.charAt(i);
                temp.append((ch == 'z') ? 'a' : (char)(ch + 1));
            }
            word.append(temp);
        }
        return word.charAt(k - 1);
    }
}
