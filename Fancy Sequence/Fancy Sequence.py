# Solution for Fancy Sequence in PY

class Fancy:

    MOD = 10**9 + 7

    def __init__(self):
        self.normalizedSequence = []
        self.currentAdder = 0
        self.currentMultiplier = 1

    def modPower(self, base, exponent):
        if exponent == 0:
            return 1

        half = self.modPower(base, exponent // 2)
        result = (half * half) % self.MOD

        if exponent % 2 == 1:
            result = (result * base) % self.MOD

        return result

    def append(self, val):

        normalizedValue = ((val - self.currentAdder) % self.MOD + self.MOD) \
                          * self.modPower(self.currentMultiplier, self.MOD - 2) % self.MOD

        self.normalizedSequence.append(normalizedValue)

    def addAll(self, inc):
        self.currentAdder = (self.currentAdder + inc) % self.MOD

    def multAll(self, m):
        self.currentAdder = (self.currentAdder * m) % self.MOD
        self.currentMultiplier = (self.currentMultiplier * m) % self.MOD

    def getIndex(self, idx):

        if idx >= len(self.normalizedSequence):
            return -1

        return (self.normalizedSequence[idx] * self.currentMultiplier + self.currentAdder) % self.MOD
