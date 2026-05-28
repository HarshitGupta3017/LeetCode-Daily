# Solution for Longest Common Suffix Queries in PY

class Solution:

    class TrieNode:
        def __init__(self, index):
            self.wordIndex = index
            self.children = [-1] * 26

    def __init__(self):
        self.trie = []

    # Create node and return its index
    def createNode(self, wordIndex):
        self.trie.append(self.TrieNode(wordIndex))
        return len(self.trie) - 1

    def insertWord(self, currentIndex, wordsContainer):
        currentWord = wordsContainer[currentIndex]

        node = 0  # root

        # Insert in reverse order
        for pos in range(len(currentWord) - 1, -1, -1):

            ch = ord(currentWord[pos]) - ord('a')

            # Create child if absent
            if self.trie[node].children[ch] == -1:
                self.trie[node].children[ch] = self.createNode(currentIndex)

            node = self.trie[node].children[ch]

            storedIndex = self.trie[node].wordIndex

            # Keep shortest word index
            if len(wordsContainer[storedIndex]) > len(wordsContainer[currentIndex]):
                self.trie[node].wordIndex = currentIndex

    def searchWord(self, queryWord):

        node = 0

        # Default answer = globally shortest word
        bestIndex = self.trie[0].wordIndex

        # Traverse in reverse
        for pos in range(len(queryWord) - 1, -1, -1):

            ch = ord(queryWord[pos]) - ord('a')

            # No further suffix match
            if self.trie[node].children[ch] == -1:
                return bestIndex

            node = self.trie[node].children[ch]

            # Deeper suffix match
            bestIndex = self.trie[node].wordIndex

        return bestIndex

    def stringIndices(self, wordsContainer, wordsQuery):

        n = len(wordsContainer)
        m = len(wordsQuery)

        # Root node
        self.createNode(0)

        # Build trie
        for i in range(n):

            # Update root with globally shortest word
            if len(wordsContainer[self.trie[0].wordIndex]) > len(wordsContainer[i]):
                self.trie[0].wordIndex = i

            self.insertWord(i, wordsContainer)

        # Answer queries
        result = [0] * m

        for i in range(m):
            result[i] = self.searchWord(wordsQuery[i])

        return result
