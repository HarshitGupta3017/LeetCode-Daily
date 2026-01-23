# Solution for Minimum Pair Removal to Sort Array II in PY

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        import heapq

        n = len(nums)
        values = nums[:]

        minHeap = []
        badPairs = 0

        for i in range(n - 1):
            heapq.heappush(minHeap, (values[i] + values[i + 1], i))
            if values[i] > values[i + 1]:
                badPairs += 1

        prevIndex = [i - 1 for i in range(n)]
        nextIndex = [i + 1 for i in range(n)]

        operations = 0

        def is_valid_pair(left, pair_sum):
            right = nextIndex[left]
            if right >= n or prevIndex[right] != left:
                return False
            return values[left] + values[right] == pair_sum

        while badPairs > 0:
            while True:
                pair_sum, left = heapq.heappop(minHeap)
                if is_valid_pair(left, pair_sum):
                    break

            right = nextIndex[left]
            leftNeighbor = prevIndex[left]
            rightNeighbor = nextIndex[right]

            if values[left] > values[right]:
                badPairs -= 1

            merged = values[left] + values[right]

            if leftNeighbor >= 0:
                if values[leftNeighbor] <= values[left] and values[leftNeighbor] > merged:
                    badPairs += 1
                elif values[leftNeighbor] > values[left] and values[leftNeighbor] <= merged:
                    badPairs -= 1

            if rightNeighbor < n:
                if values[rightNeighbor] >= values[right] and values[rightNeighbor] < merged:
                    badPairs += 1
                elif values[rightNeighbor] < values[right] and values[rightNeighbor] >= merged:
                    badPairs -= 1

            if leftNeighbor >= 0:
                heapq.heappush(minHeap, (values[leftNeighbor] + merged, leftNeighbor))

            if rightNeighbor < n:
                heapq.heappush(minHeap, (merged + values[rightNeighbor], left))
                prevIndex[rightNeighbor] = left

            nextIndex[left] = rightNeighbor
            values[left] = merged
            operations += 1

        return operations
