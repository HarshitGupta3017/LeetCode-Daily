# Solution for Lexicographical Numbers in PY

class Solution:
    def lexicalOrder(self, n: int) -> list[int]:
        def generateLexical(currentNum: int):
            if currentNum > n:
                return

            result.append(currentNum)

            for digit in range(10):
                nextNum = currentNum * 10 + digit
                if nextNum > n:
                    return
                generateLexical(nextNum)

        result = []
        for start in range(1, 10):
            generateLexical(start)

        return result
