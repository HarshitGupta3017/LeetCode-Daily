# Solution for Find the Lexicographically Largest String From the Box I in PY

class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        if numFriends == 1: 
            return word

        totalLength = len(word)
        maxChunkLength = totalLength - (numFriends - 1)
        maxString = ""

        for start in range(totalLength):
            currentChunkLength = min(maxChunkLength, totalLength - start)
            currentSubstring = word[start:start + currentChunkLength]
            if currentSubstring > maxString:
                maxString = currentSubstring     

        return maxString
