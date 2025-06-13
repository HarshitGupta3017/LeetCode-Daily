class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        def isValid(nums: List[int], maxDiffAllowed: int, p: int) -> bool:
            index = 0
            pairCount = 0
            n = len(nums)

            while index < n - 1:
                if nums[index + 1] - nums[index] <= maxDiffAllowed:
                    pairCount += 1
                    index += 2  # Use both elements in the pair
                else:
                    index += 1  # Skip to next element

            return pairCount >= p

        nums.sort()
        low = 0
        high = nums[-1] - nums[0]
        result = float('inf')

        while low <= high:
            mid = (low + high) // 2
            if isValid(nums, mid, p):
                result = mid
                high = mid - 1
            else:
                low = mid + 1

        return result
