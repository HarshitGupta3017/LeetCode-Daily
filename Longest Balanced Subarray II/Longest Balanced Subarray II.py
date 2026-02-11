# Solution for Longest Balanced Subarray II in PY

class Solution:

    def longestBalanced(self, nums: List[int]) -> int:

        self.n = len(nums)

        self.segMin = [0] * (4 * self.n)
        self.segMax = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)

        maxLength = 0
        lastIndex = {}

        def propagate(node, left, right):

            if self.lazy[node] != 0:

                self.segMin[node] += self.lazy[node]
                self.segMax[node] += self.lazy[node]

                if left != right:
                    self.lazy[2 * node + 1] += self.lazy[node]
                    self.lazy[2 * node + 2] += self.lazy[node]

                self.lazy[node] = 0

        def updateRange(start, end, node, left, right, val):

            propagate(node, left, right)

            if left > end or right < start:
                return

            if left >= start and right <= end:
                self.lazy[node] += val
                propagate(node, left, right)
                return

            mid = (left + right) // 2

            updateRange(start, end, 2 * node + 1, left, mid, val)
            updateRange(start, end, 2 * node + 2, mid + 1, right, val)

            self.segMin[node] = min(
                self.segMin[2 * node + 1],
                self.segMin[2 * node + 2]
            )
            self.segMax[node] = max(
                self.segMax[2 * node + 1],
                self.segMax[2 * node + 2]
            )

        def findLeftMostZero(node, left, right):

            propagate(node, left, right)

            if self.segMin[node] > 0 or self.segMax[node] < 0:
                return -1

            if left == right:
                return left

            mid = (left + right) // 2

            leftResult = findLeftMostZero(2 * node + 1, left, mid)
            if leftResult != -1:
                return leftResult

            return findLeftMostZero(2 * node + 2, mid + 1, right)

        for right in range(self.n):

            contribution = 1 if nums[right] % 2 == 0 else -1

            previousIndex = lastIndex.get(nums[right], -1)

            if previousIndex != -1:
                updateRange(0, previousIndex,
                            0, 0, self.n - 1,
                            -contribution)

            updateRange(0, right,
                        0, 0, self.n - 1,
                        contribution)

            left = findLeftMostZero(0, 0, self.n - 1)

            if left != -1:
                maxLength = max(maxLength, right - left + 1)

            lastIndex[nums[right]] = right

        return maxLength
