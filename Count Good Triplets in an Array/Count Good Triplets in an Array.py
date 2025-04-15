# Solution for Count Good Triplets in an Array in PY

class SegmentTree:
    def __init__(self, size):
        self.n = size
        self.tree = [0] * (4 * size)

    def update(self, i, l, r, idx):
        if l == r:
            self.tree[i] = 1
            return
        mid = (l + r) // 2
        if idx <= mid:
            self.update(2 * i + 1, l, mid, idx)
        else:
            self.update(2 * i + 2, mid + 1, r, idx)
        self.tree[i] = self.tree[2 * i + 1] + self.tree[2 * i + 2]

    def query(self, qs, qe, i, l, r):
        if r < qs or l > qe:
            return 0
        if qs <= l and r <= qe:
            return self.tree[i]
        mid = (l + r) // 2
        left = self.query(qs, qe, 2 * i + 1, l, mid)
        right = self.query(qs, qe, 2 * i + 2, mid + 1, r)
        return left + right

class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        mp = {val: idx for idx, val in enumerate(nums2)}
        seg_tree = SegmentTree(n)
        result = 0

        seg_tree.update(0, 0, n - 1, mp[nums1[0]])

        for i in range(1, n):
            idx = mp[nums1[i]]
            left_common = seg_tree.query(0, idx, 0, 0, n - 1)
            left_not_common = i - left_common
            right_common = (n - 1 - idx) - left_not_common
            result += left_common * right_common
            seg_tree.update(0, 0, n - 1, idx)

        return result
