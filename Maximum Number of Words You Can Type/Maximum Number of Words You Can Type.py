# Solution for Maximum Number of Words You Can Type in PY

class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        # Step 1: Track broken letters
        isBroken = set(brokenLetters)

        fullyTypableCount = 0
        canTypeCurrentWord = True

        # Step 2: Traverse each character
        for ch in text:
            if ch == ' ':
                if canTypeCurrentWord:
                    fullyTypableCount += 1
                canTypeCurrentWord = True  # reset for next word
            elif ch in isBroken:
                canTypeCurrentWord = False

        # Step 3: Handle last word
        if canTypeCurrentWord:
            fullyTypableCount += 1

        return fullyTypableCount
