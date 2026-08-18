# Solution for Find the Largest Almost Missing Integer in PY

class Solution:
    def largestInteger(self, nums, k):
        n = len(nums)
        freq = [0] * 51

        for x in nums:
            freq[x] += 1

        if k == n:
            return max(nums)

        if k == 1:
            for x in range(50, -1, -1):
                if freq[x] == 1:
                    return x
            return -1

        ans = -1
        if freq[nums[0]] == 1:
            ans = max(ans, nums[0])
        if freq[nums[-1]] == 1:
            ans = max(ans, nums[-1])

        return ans
