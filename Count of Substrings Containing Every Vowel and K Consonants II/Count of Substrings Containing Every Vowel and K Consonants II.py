# Solution for Count of Substrings Containing Every Vowel and K Consonants II in PY

class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        mp = {} # vowelsCount
        n = len(word)
        nextConsonant = [n] * n
        lastConsIdx = n # consonant index
        for i in range(n - 1, -1, -1):
            nextConsonant[i] = lastConsIdx
            if word[i] not in vowels:
                lastConsIdx = i
        i = j = cons = res = 0
        while j < n:
            if word[j] in vowels:
                mp[word[j]] = mp.get(word[j], 0) + 1
            else:
                cons += 1
            while cons > k:
                ch = word[i]
                if ch in vowels:
                    mp[ch] -= 1
                    if mp[ch] == 0:
                        del mp[ch]
                else:
                    cons -= 1
                i += 1
            while i < n and len(mp) == 5 and cons == k:
                res += (nextConsonant[j] - j)
                ch = word[i]
                if ch in vowels:
                    mp[ch] -= 1
                    if mp[ch] == 0:
                        del mp[ch]
                else:
                    cons -= 1
                i += 1
            j += 1
        return res
