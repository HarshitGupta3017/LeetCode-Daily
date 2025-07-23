# Solution for Maximum Score From Removing Substrings in PY

class Solution:
    def removeSubstr(self, s: str, pattern: str) -> str:
        stack = []
        for ch in s:
            stack.append(ch)
            if len(stack) >= 2 and stack[-2] == pattern[0] and stack[-1] == pattern[1]:
                stack.pop()
                stack.pop()
        return ''.join(stack)

    def maximumGain(self, s: str, x: int, y: int) -> int:
        first, second = ("ab", "ba") if x > y else ("ba", "ab")
        afterFirst = self.removeSubstr(s, first)
        firstGain = (len(s) - len(afterFirst)) // 2 * max(x, y)
        afterSecond = self.removeSubstr(afterFirst, second)
        secondGain = (len(afterFirst) - len(afterSecond)) // 2 * min(x, y)
        return firstGain + secondGain
