# Solution for K-th Smallest in Lexicographical Order in PY

class Solution:
    def countNumbersWithPrefix(self, prefix: int, nextPrefix: int, n: int) -> int:
        totalCount = 0
        while prefix <= n:
            totalCount += min(n + 1, nextPrefix) - prefix
            prefix *= 10
            nextPrefix *= 10
        return totalCount

    def findKthNumber(self, n: int, k: int) -> int:
        current = 1
        k -= 1

        while k > 0:
            count = self.countNumbersWithPrefix(current, current + 1, n)
            if count <= k:
                current += 1
                k -= count
            else:
                current *= 10
                k -= 1

        return current
