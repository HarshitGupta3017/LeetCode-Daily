// Solution for Longest Common Suffix Queries in JAVA

class Solution {

    static class TrieNode {
        int wordIndex;
        int[] children;

        TrieNode(int index) {
            wordIndex = index;
            children = new int[26];

            // initialize with -1
            java.util.Arrays.fill(children, -1);
        }
    }

    List<TrieNode> trie = new ArrayList<>();

    // Create node and return index
    int createNode(int wordIndex) {
        trie.add(new TrieNode(wordIndex));
        return trie.size() - 1;
    }

    void insertWord(int currentIndex, String[] wordsContainer) {
        String currentWord = wordsContainer[currentIndex];
        int node = 0;

        // Insert in reverse order
        for (int pos = currentWord.length() - 1; pos >= 0; pos--) {

            int ch = currentWord.charAt(pos) - 'a';

            // Create child if absent
            if (trie.get(node).children[ch] == -1) {
                trie.get(node).children[ch] = createNode(currentIndex);
            }

            node = trie.get(node).children[ch];

            int storedIndex = trie.get(node).wordIndex;

            // Keep shortest word index
            if (wordsContainer[storedIndex].length() >
                wordsContainer[currentIndex].length()) {

                trie.get(node).wordIndex = currentIndex;
            }
        }
    }

    int searchWord(String queryWord) {

        int node = 0;

        // Default answer = globally shortest word
        int bestIndex = trie.get(0).wordIndex;

        for (int pos = queryWord.length() - 1; pos >= 0; pos--) {

            int ch = queryWord.charAt(pos) - 'a';

            // No more suffix match
            if (trie.get(node).children[ch] == -1) {
                return bestIndex;
            }

            node = trie.get(node).children[ch];

            // deeper suffix match
            bestIndex = trie.get(node).wordIndex;
        }

        return bestIndex;
    }

    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {

        int n = wordsContainer.length;
        int m = wordsQuery.length;

        // Root node
        createNode(0);

        // Build trie
        for (int i = 0; i < n; i++) {

            // Update root with globally shortest word
            if (wordsContainer[trie.get(0).wordIndex].length() >
                wordsContainer[i].length()) {

                trie.get(0).wordIndex = i;
            }

            insertWord(i, wordsContainer);
        }

        // Answer queries
        int[] result = new int[m];

        for (int i = 0; i < m; i++) {
            result[i] = searchWord(wordsQuery[i]);
        }

        return result;
    }
}
