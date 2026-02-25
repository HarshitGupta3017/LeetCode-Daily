# Solution for Sort Integers by The Number of 1 Bits in PY

class Solution:
    def sortByBits(self, arr):
        return sorted(arr, key=lambda x: (x.bit_count(), x))
