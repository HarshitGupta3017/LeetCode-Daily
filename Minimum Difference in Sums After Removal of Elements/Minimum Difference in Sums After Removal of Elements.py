# Solution for Minimum Difference in Sums After Removal of Elements in PY

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        N = len(nums)
        n = N // 3

        left_min_sum = [0] * N
        right_max_sum = [0] * N

        max_heap = []
        left_sum = 0

        for i in range(2 * n):
            heappush(max_heap, -nums[i])
            left_sum += nums[i]
            if len(max_heap) > n:
                left_sum += heappop(max_heap)
            left_min_sum[i] = left_sum

        min_heap = []
        right_sum = 0

        for i in range(N - 1, n - 1, -1):
            heappush(min_heap, nums[i])
            right_sum += nums[i]
            if len(min_heap) > n:
                right_sum -= heappop(min_heap)
            right_max_sum[i] = right_sum

        result = float('inf')

        for i in range(n - 1, 2 * n):
            diff = left_min_sum[i] - right_max_sum[i + 1]
            result = min(result, diff)

        return result
