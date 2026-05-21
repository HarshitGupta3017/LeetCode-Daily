# Solution for Find the Length of the Longest Common Prefix in PY

class Solution:
    def longestCommonPrefix(self, arr1, arr2):

        prefixes = set()
        longest = 0

        # Store all prefixes from arr1
        for num in arr1:
            while num > 0 and num not in prefixes:
                prefixes.add(num)
                num //= 10

        # Check arr2 prefixes
        for num in arr2:

            while num > 0 and num not in prefixes:
                num //= 10

            if num > 0:
                longest = max(longest, len(str(num)))

        return longest
