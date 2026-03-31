# Solution for Lexicographically Smallest Generated String in PY

class Solution:

    # Helper function
    def isSame(self, word, str2, start, m):
        for j in range(m):
            if word[start + j] != str2[j]:
                return False
        return True

    def generateString(self, str1, str2):

        n = len(str1)
        m = len(str2)

        totalLen = n + m - 1

        word = ['$',] * totalLen

        # STEP 1: Handle 'T'
        for i in range(n):
            if str1[i] == 'T':
                for j in range(m):
                    pos = i + j

                    if word[pos] != '$' and word[pos] != str2[j]:
                        return ""

                    word[pos] = str2[j]

        # STEP 2: Fill remaining with 'a'
        canModify = [False] * totalLen

        for i in range(totalLen):
            if word[i] == '$':
                word[i] = 'a'
                canModify[i] = True

        # STEP 3: Handle 'F'
        for i in range(n):
            if str1[i] == 'F':

                if self.isSame(word, str2, i, m):

                    changed = False

                    for j in range(i + m - 1, i - 1, -1):
                        if canModify[j]:
                            word[j] = 'b'
                            changed = True
                            break

                    if not changed:
                        return ""

        return "".join(word)
