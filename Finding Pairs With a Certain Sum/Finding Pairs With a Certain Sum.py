# Solution for Finding Pairs With a Certain Sum in PY

class FindSumPairs:
    def __init__(self, nums1: list[int], nums2: list[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.freq_map = Counter(nums2)

    def add(self, index: int, val: int) -> None:
        old_val = self.nums2[index]
        self.freq_map[old_val] -= 1

        self.nums2[index] += val
        new_val = self.nums2[index]
        self.freq_map[new_val] += 1

    def count(self, tot: int) -> int:
        total_pairs = 0
        for num1 in self.nums1:
            required = tot - num1
            total_pairs += self.freq_map.get(required, 0)
        return total_pairs
