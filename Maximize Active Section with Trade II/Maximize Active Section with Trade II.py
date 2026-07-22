# Solution for Maximize Active Section with Trade II in PY

from bisect import bisect_left, bisect_right

class Solution:
    # -----------------------------------------------------------------------
    # Segment Tree
    # -----------------------------------------------------------------------

    def buildSegTree(self, node, nodeL, nodeR, segTree, arr):
        if nodeL == nodeR:
            segTree[node] = arr[nodeL]
            return

        mid = nodeL + (nodeR - nodeL) // 2

        self.buildSegTree(2 * node + 1, nodeL, mid, segTree, arr)
        self.buildSegTree(2 * node + 2, mid + 1, nodeR, segTree, arr)

        segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2])

    def buildSegmentTree(self, arr):
        segTree = [0] * (4 * len(arr))
        self.buildSegTree(0, 0, len(arr) - 1, segTree, arr)
        return segTree

    def querySegTree(self, qL, qR, node, nodeL, nodeR, segTree):
        if nodeL > qR or nodeR < qL:
            return float("-inf")

        if qL <= nodeL and nodeR <= qR:
            return segTree[node]

        mid = nodeL + (nodeR - nodeL) // 2

        return max(
            self.querySegTree(qL, qR, 2 * node + 1, nodeL, mid, segTree),
            self.querySegTree(qL, qR, 2 * node + 2, mid + 1, nodeR, segTree),
        )

    def rangeMax(self, segTree, n, l, r):
        return self.querySegTree(l, r, 0, 0, n - 1, segTree)

    def maxActiveSectionsAfterTrade(self, s: str, queries):
        n = len(s)

        totalActive = s.count('1')

        zeroStart = []
        zeroEnd = []

        i = 0
        while i < n:
            if s[i] == '0':
                start = i
                while i < n and s[i] == '0':
                    i += 1
                zeroStart.append(start)
                zeroEnd.append(i - 1)
            else:
                i += 1

        numBlocks = len(zeroStart)

        if numBlocks < 2:
            return [totalActive] * len(queries)

        blockLen = [
            zeroEnd[k] - zeroStart[k] + 1
            for k in range(numBlocks)
        ]

        pairSum = [
            blockLen[k] + blockLen[k + 1]
            for k in range(numBlocks - 1)
        ]

        segTree = self.buildSegmentTree(pairSum)
        numPairs = len(pairSum)

        ans = []

        for l, r in queries:

            firstBlock = bisect_left(zeroEnd, l)
            lastBlock = bisect_right(zeroStart, r) - 1

            maxGain = 0

            if firstBlock < lastBlock:

                firstEffLen = (
                    zeroEnd[firstBlock]
                    - max(zeroStart[firstBlock], l)
                    + 1
                )

                lastEffLen = (
                    min(zeroEnd[lastBlock], r)
                    - zeroStart[lastBlock]
                    + 1
                )

                if lastBlock - firstBlock == 1:
                    maxGain = firstEffLen + lastEffLen
                else:
                    gainLeft = firstEffLen + blockLen[firstBlock + 1]
                    gainRight = blockLen[lastBlock - 1] + lastEffLen
                    gainMiddle = self.rangeMax(
                        segTree,
                        numPairs,
                        firstBlock + 1,
                        lastBlock - 2,
                    )

                    maxGain = max(gainLeft, gainRight, gainMiddle)

            ans.append(totalActive + maxGain)

        return ans
