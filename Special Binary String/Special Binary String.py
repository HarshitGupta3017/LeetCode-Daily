# Solution for Special Binary String in PY

class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        blocks = []
        balance = start = 0

        for i, ch in enumerate(s):
            balance += 1 if ch == '1' else -1
            if balance == 0:
                inner = s[start + 1:i]
                blocks.append("1" + self.makeLargestSpecial(inner) + "0")
                start = i + 1

        blocks.sort(reverse=True)
        return "".join(blocks)
