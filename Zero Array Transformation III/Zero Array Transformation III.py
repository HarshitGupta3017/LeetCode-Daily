# Solution for Zero Array Transformation III in PY

import heapq

class Solution:
    def maxRemoval(self, nums, queries):
        n, q = len(nums), len(queries)
        queries.sort()
        maxHeap = []
        past = []
        j = used = 0
        for i in range(n):
            while j < q and queries[j][0] == i:
                heapq.heappush(maxHeap, -queries[j][1])
                j += 1
            nums[i] -= len(past)
            while nums[i] > 0 and maxHeap and -maxHeap[0] >= i:
                end = -heapq.heappop(maxHeap)
                heapq.heappush(past, end)
                used += 1
                nums[i] -= 1
            if nums[i] > 0:
                return -1
            while past and past[0] <= i:
                heapq.heappop(past)
        return q - used
