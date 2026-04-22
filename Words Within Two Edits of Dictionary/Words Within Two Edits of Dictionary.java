// Solution for Words Within Two Edits of Dictionary in JAVA

class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> matchingWords = new ArrayList<>();

        for (String queryWord : queries) {
            for (String dictWord : dictionary) {
                int mismatchCount = 0;

                for (int i = 0; i < queryWord.length(); i++) {
                    if (queryWord.charAt(i) != dictWord.charAt(i)) {
                        mismatchCount++;
                    }

                    if (mismatchCount > 2) {
                        break;
                    }
                }

                if (mismatchCount <= 2) {
                    matchingWords.add(queryWord);
                    break;
                }
            }
        }

        return matchingWords;
    }
}
