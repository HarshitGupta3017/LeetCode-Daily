# Solution for Maximal Rectangle in PY

class Solution:

    # Next Smaller to Right
    def findNSR(self, heights, n):
        stack = []
        NSR = [0] * n

        stack.append(n - 1)
        NSR[n - 1] = n

        for i in range(n - 2, -1, -1):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            NSR[i] = stack[-1] if stack else n
            stack.append(i)

        return NSR

    # Next Smaller to Left
    def findNSL(self, heights, n):
        stack = []
        NSL = [0] * n

        stack.append(0)
        NSL[0] = -1

        for i in range(1, n):
            while stack and heights[stack[-1]] >= heights[i]:
                stack.pop()
            NSL[i] = stack[-1] if stack else -1
            stack.append(i)

        return NSL

    # Largest rectangle in histogram
    def findArea(self, heights, n):
        NSR = self.findNSR(heights, n)
        NSL = self.findNSL(heights, n)

        maxArea = 0
        for i in range(n):
            height = heights[i]
            width = NSR[i] - NSL[i] - 1
            maxArea = max(maxArea, height * width)

        return maxArea

    # Maximal rectangle in binary matrix
    def maximalRectangle(self, matrix):
        if not matrix:
            return 0

        m, n = len(matrix), len(matrix[0])
        heights = [0] * n

        # First row
        for col in range(n):
            heights[col] = 1 if matrix[0][col] == '1' else 0

        maxArea = self.findArea(heights, n)

        # Remaining rows
        for row in range(1, m):
            for col in range(n):
                if matrix[row][col] == '0':
                    heights[col] = 0
                else:
                    heights[col] += 1
            maxArea = max(maxArea, self.findArea(heights, n))

        return maxArea
