# Solution for Count the Number of Powerful Integers in PY

class Solution:

    def solve(self, str_val: str, suff: str, limit: int) -> int:
        if len(str_val) < len(suff):
            return 0

        count = 0
        trail_str = str_val[-len(suff):]
        rem_len = len(str_val) - len(suff)

        for i in range(rem_len):
            digit = int(str_val[i])
            if digit <= limit:
                count += digit * (limit + 1) ** (rem_len - i - 1)
            else:
                count += (limit + 1) ** (rem_len - i)
                return count

        if trail_str >= suff:
            count += 1
        return count

    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        start_str = str(start - 1)
        finish_str = str(finish)
        return self.solve(finish_str, s, limit) - self.solve(start_str, s, limit)
