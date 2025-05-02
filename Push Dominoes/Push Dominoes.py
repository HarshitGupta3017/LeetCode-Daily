# Solution for Push Dominoes in PY

class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        rightClosestL = [-1] * n
        leftClosestR = [-1] * n
        # Fill leftClosestR (closest R to the left)
        for i in range(n):
            if dominoes[i] == 'R':
                leftClosestR[i] = i
            elif dominoes[i] == '.':
                leftClosestR[i] = leftClosestR[i - 1] if i > 0 else -1
            else:  # 'L'
                leftClosestR[i] = -1
        # Fill rightClosestL (closest L to the right)
        for i in range(n - 1, -1, -1):
            if dominoes[i] == 'L':
                rightClosestL[i] = i
            elif dominoes[i] == '.':
                rightClosestL[i] = rightClosestL[i + 1] if i < n - 1 else -1
            else:  # 'R'
                rightClosestL[i] = -1
        result = []
        for i in range(n):
            distRightL = abs(i - rightClosestL[i])
            distLeftR = abs(i - leftClosestR[i])
            if leftClosestR[i] == rightClosestL[i]:
                result.append('.')
            elif leftClosestR[i] == -1:
                result.append('L')
            elif rightClosestL[i] == -1:
                result.append('R')
            elif distRightL == distLeftR:
                result.append('.')
            else:
                result.append('L' if distRightL < distLeftR else 'R')
        return ''.join(result)
