# Solution for Find Resultant Array After Removing Anagrams in PY

class Solution:
    def checkAnagram(self, s1: str, s2: str) -> bool:
        arr = [0] * 26
        for ch in s1:
            arr[ord(ch) - ord('a')] += 1
        
        for ch in s2:
            arr[ord(ch) - ord('a')] -= 1
        
        for i in range(26):
            if arr[i] != 0:
                return False
        return True

    def removeAnagrams(self, words: List[str]) -> List[str]:
        result = [words[0]]
        for i in range(1, len(words)):
            if self.checkAnagram(result[-1], words[i]) == False:
                result.append(words[i])
        return result
