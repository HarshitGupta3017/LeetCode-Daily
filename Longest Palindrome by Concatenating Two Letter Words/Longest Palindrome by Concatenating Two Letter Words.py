# Solution for Longest Palindrome by Concatenating Two Letter Words in PY

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        mp = Counter(words)
        res = 0
        center_used = False
        for word in words:
            rev = word[::-1]
            if word != rev:
                if mp[word] > 0 and mp[rev] > 0:
                    mp[word] -= 1
                    mp[rev] -= 1
                    res += 4
            else:
                if mp[word] >= 2:
                    mp[word] -= 2
                    res += 4
                elif mp[word] == 1 and not center_used:
                    mp[word] -= 1
                    center_used = True
                    res += 2
        return res
