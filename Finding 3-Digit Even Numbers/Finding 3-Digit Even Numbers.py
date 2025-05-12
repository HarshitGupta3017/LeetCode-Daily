# Solution for Finding 3-Digit Even Numbers in PY

class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        res = []
        freq = [0] * 10
        for digit in digits:
            freq[digit] += 1

        for i in range(1, 10):
            if (freq[i] == 0):
                continue
            freq[i] -= 1
            for j in range(0, 10):
                if (freq[j] == 0):
                    continue
                freq[j] -= 1
                for k in range(0, 9, 2):
                    if (freq[k] == 0):
                        continue
                    freq[k] -= 1
                    num = i * 100 + j * 10 + k
                    res.append(num)
                    freq[k] += 1
                freq[j] += 1
            freq[i] += 1
        return res
