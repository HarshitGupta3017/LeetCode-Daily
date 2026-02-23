# Solution for Check If a String Contains All Binary Codes of Size K in PY

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:

        total_codes_needed = 1 << k
        seen = set()

        for i in range(k, len(s) + 1):

            sub = s[i - k:i]

            if sub not in seen:
                seen.add(sub)
                total_codes_needed -= 1

            if total_codes_needed == 0:
                return True

        return False
