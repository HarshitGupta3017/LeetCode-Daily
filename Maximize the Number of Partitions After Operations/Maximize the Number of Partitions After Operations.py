# Solution for Maximize the Number of Partitions After Operations in PY

class Solution:
    def maxPartitionsAfterOperations(self, s: str, k: int) -> int:
        from functools import lru_cache
        ALPHA = 26

        @lru_cache(None)
        def solve(i: int, mask: int, can_modify: bool) -> int:
            if i >= len(s):
                return 0

            ch_bit = 1 << (ord(s[i]) - ord('a'))
            new_mask = mask | ch_bit
            unique = new_mask.bit_count()

            # Case 1: Without modification
            if unique > k:
                res = 1 + solve(i + 1, ch_bit, can_modify)
            else:
                res = solve(i + 1, new_mask, can_modify)

            # Case 2: Try modifying current char
            if can_modify:
                for rep in range(ALPHA):
                    mod_mask = mask | (1 << rep)
                    mod_unique = mod_mask.bit_count()
                    if mod_unique > k:
                        res = max(res, 1 + solve(i + 1, 1 << rep, False))
                    else:
                        res = max(res, solve(i + 1, mod_mask, False))

            return res

        return solve(0, 0, True) + 1
