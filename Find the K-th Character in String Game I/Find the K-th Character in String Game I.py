# Solution for Find the K-th Character in String Game I in PY

class Solution:
    def kthCharacter(self, k: int) -> str:
        word = "a"
        while len(word) < k:
            temp = ""
            for ch in word:
                temp += 'a' if ch == 'z' else chr(ord(ch) + 1)
            word += temp
        return word[k - 1]
