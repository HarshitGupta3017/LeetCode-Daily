# Solution for Find Most Frequent Vowel and Consonant in PY

class Solution:
    def maxFreqSum(self, s: str) -> int:
        max_consonant_freq = 0
        max_vowel_freq = 0
        frequency = [0] * 26  # frequency for 'a' to 'z'

        for ch in s:
            idx = ord(ch) - ord('a')
            frequency[idx] += 1

            if ch in "aeiou":  # vowel check
                max_vowel_freq = max(max_vowel_freq, frequency[idx])
            else:  # consonant
                max_consonant_freq = max(max_consonant_freq, frequency[idx])

        return max_consonant_freq + max_vowel_freq
