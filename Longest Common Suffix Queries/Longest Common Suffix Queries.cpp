// Solution for Longest Common Suffix Queries in CPP

class Solution {
public:
    struct TrieNode {
        int wordIndex;        // best matching container word index
        int children[26];     // ✅ int indices instead of pointers (4 bytes vs 8 bytes)

        TrieNode(int index) {
            wordIndex = index;
            fill(children, children + 26, -1);  // -1 means no child
        }
    };

    vector<TrieNode> trie;  // ✅ all nodes in one contiguous block

    // Create node and return its index in trie vector
    int createNode(int wordIndex) {
        trie.push_back(TrieNode(wordIndex));
        return trie.size() - 1;
    }

    void insertWord(int currentIndex, vector<string>& wordsContainer) {
        string& currentWord = wordsContainer[currentIndex];
        int wordLength = currentWord.length();

        int node = 0;  // start from root (index 0)

        // Insert in reverse order so trie represents suffixes
        for (int position = wordLength - 1; position >= 0; position--) {
            int characterIndex = currentWord[position] - 'a';

            // Create child node if path doesn't exist
            if (trie[node].children[characterIndex] == -1) {
                trie[node].children[characterIndex] = createNode(currentIndex);
            }

            node = trie[node].children[characterIndex];

            // Update stored index if current word has smaller length
            // Earlier index preserved automatically (insertion in order)
            int storedIndex = trie[node].wordIndex;
            if (wordsContainer[storedIndex].size() > wordsContainer[currentIndex].size()) {
                trie[node].wordIndex = currentIndex;
            }
        }
    }

    int searchWord(string& queryWord) {
        int node = 0;  // start from root

        // Default = globally smallest word at root
        int bestIndex = trie[0].wordIndex;
        int wordLength = queryWord.length();

        // Traverse in reverse (suffix matching)
        for (int position = wordLength - 1; position >= 0; position--) {
            int characterIndex = queryWord[position] - 'a';

            // No further suffix match possible
            if (trie[node].children[characterIndex] == -1)
                return bestIndex;

            node = trie[node].children[characterIndex];

            // Deeper match = better suffix
            bestIndex = trie[node].wordIndex;
        }

        return bestIndex;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int containerSize = wordsContainer.size();
        int querySize     = wordsQuery.size();

        // Reserve space upfront to avoid reallocations
        // Max nodes = total characters in all container words
        trie.reserve(500001);

        // Root node starts with index 0
        createNode(0);

        // Build suffix trie
        for (int index = 0; index < containerSize; index++) {

            // Update root's best index (globally shortest word)
            if (wordsContainer[trie[0].wordIndex].size() >
                wordsContainer[index].size()) {
                trie[0].wordIndex = index;
            }

            insertWord(index, wordsContainer);
        }

        // Answer each query
        vector<int> result(querySize);
        for (int queryIndex = 0; queryIndex < querySize; queryIndex++) {
            result[queryIndex] = searchWord(wordsQuery[queryIndex]);
        }

        return result;
    }
};
