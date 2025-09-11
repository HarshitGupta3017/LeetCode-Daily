# Solution for Sort Vowels in a String in PY

class Solution:
    def sortVowels(self, s: str) -> str:
        # Helper function to check if a character is a vowel
        def isVowel(ch: str) -> bool:
            return ch.lower() in "aeiou"

        # Step 1: Count frequency of each vowel (case-sensitive)
        vowelFrequency = {}
        for ch in s:
            if isVowel(ch):
                vowelFrequency[ch] = vowelFrequency.get(ch, 0) + 1

        # Step 2: Define vowels in sorted order (uppercase before lowercase)
        sortedVowelOrder = "AEIOUaeiou"

        # Step 3: Replace vowels in the string with sorted vowels
        s_list = list(s)  # convert to list since strings are immutable
        vowelIndex = 0

        for i in range(len(s_list)):
            if isVowel(s_list[i]):
                # Find the next available vowel from the frequency map
                while vowelFrequency.get(sortedVowelOrder[vowelIndex], 0) == 0:
                    vowelIndex += 1

                # Replace and decrement frequency
                s_list[i] = sortedVowelOrder[vowelIndex]
                vowelFrequency[sortedVowelOrder[vowelIndex]] -= 1

        return "".join(s_list)  # Final string with vowels sorted
