# Solution for Smallest Subarrays With Maximum Bitwise OR in PY

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        latest_bit_position = [-1] * 32

        for i in range(n - 1, -1, -1):
            farthest_reach = i
            for bit in range(32):
                if not (nums[i] & (1 << bit)):
                    if latest_bit_position[bit] != -1:
                        farthest_reach = max(farthest_reach, latest_bit_position[bit])
                else:
                    latest_bit_position[bit] = i

            result[i] = farthest_reach - i + 1

        return result
