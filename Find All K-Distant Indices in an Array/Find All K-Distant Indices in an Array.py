# Solution for Find All K-Distant Indices in an Array in PY

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        k_distant_indices = []
        n = len(nums)
        last_added = -1

        for j in range(n):
            if nums[j] == key:
                start = max(0, j - k)
                end = min(n - 1, j + k)

                if k_distant_indices and last_added >= start:
                    start = last_added + 1

                for i in range(start, end + 1):
                    k_distant_indices.append(i)
                    last_added = i

        return k_distant_indices
