# Solution for Vowel Spellchecker in PY

class Solution:
    def maskVowels(self, word: str) -> str:
        return "".join('*' if ch in "aeiou" else ch for ch in word)

    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        # Exact match set
        exactMatch = set(wordlist)

        # Case-insensitive and vowel-insensitive maps
        caseInsensitiveMatch = {}
        vowelInsensitiveMatch = {}

        # Preprocess wordlist
        for word in wordlist:
            lowerWord = word.lower()

            if lowerWord not in caseInsensitiveMatch:
                caseInsensitiveMatch[lowerWord] = word

            vowelMasked = self.maskVowels(lowerWord)
            if vowelMasked not in vowelInsensitiveMatch:
                vowelInsensitiveMatch[vowelMasked] = word

        result = []

        # Process queries
        for query in queries:
            if query in exactMatch:
                result.append(query)
                continue

            lowerQuery = query.lower()
            if lowerQuery in caseInsensitiveMatch:
                result.append(caseInsensitiveMatch[lowerQuery])
                continue

            vowelMaskedQuery = self.maskVowels(lowerQuery)
            if vowelMaskedQuery in vowelInsensitiveMatch:
                result.append(vowelInsensitiveMatch[vowelMaskedQuery])
                continue

            result.append("")

        return result
