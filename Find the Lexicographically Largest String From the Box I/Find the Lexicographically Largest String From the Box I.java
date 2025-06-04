// Solution for Find the Lexicographically Largest String From the Box I in JAVA

class Solution {
    public String answerString(String word, int numFriends) {
        if (numFriends == 1) return word;

        int totalLength = word.length();
        int maxChunkLength = totalLength - (numFriends - 1);
        String maxString = "";

        for (int start = 0; start < totalLength; start++) {
            int currentChunkLength = Math.min(maxChunkLength, totalLength - start);
            String currentSubstring = word.substring(start, start + currentChunkLength);
            if (currentSubstring.compareTo(maxString) > 0) {
                maxString = currentSubstring;
            }
        }

        return maxString;
    }
}
