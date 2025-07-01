# Solution for Find the Original Typed String I in PY

class Solution:
    def possibleStringCount(self, word: str) -> int:
        repeat_count = 0
        for i in range(1, len(word)):
            if word[i] == word[i - 1]:
                repeat_count += 1
        return repeat_count + 1
