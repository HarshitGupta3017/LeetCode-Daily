# Solution for Sum Game in PY

class Solution:
    def sumGame(self, num: str) -> bool:
        h = len(num) // 2
        ls = rs = lw = rw = 0

        for i, c in enumerate(num):
            if c == '?':
                if i < h: lw += 1
                else: rw += 1
            elif i < h:
                ls += int(c)
            else:
                rs += int(c)

        if (lw + rw) % 2:
            return True

        return 2 * (ls - rs) + 9 * (lw - rw) != 0
