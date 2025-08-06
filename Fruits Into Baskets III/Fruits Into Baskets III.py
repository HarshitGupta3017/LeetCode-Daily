# Solution for Fruits Into Baskets III in PY

class Solution:
    def buildSegmentTree(self, treeIndex, left, right, baskets, segmentTree):
        if left == right:
            segmentTree[treeIndex] = baskets[left]
            return

        mid = (left + right) // 2
        self.buildSegmentTree(2 * treeIndex + 1, left, mid, baskets, segmentTree)
        self.buildSegmentTree(2 * treeIndex + 2, mid + 1, right, baskets, segmentTree)
        segmentTree[treeIndex] = max(segmentTree[2 * treeIndex + 1], segmentTree[2 * treeIndex + 2])

    def placeFruitInBasket(self, treeIndex, left, right, fruit, segmentTree):
        if segmentTree[treeIndex] < fruit:
            return False

        if left == right:
            segmentTree[treeIndex] = -1
            return True

        mid = (left + right) // 2
        placed = False
        if segmentTree[2 * treeIndex + 1] >= fruit:
            placed = self.placeFruitInBasket(2 * treeIndex + 1, left, mid, fruit, segmentTree)
        else:
            placed = self.placeFruitInBasket(2 * treeIndex + 2, mid + 1, right, fruit, segmentTree)

        segmentTree[treeIndex] = max(segmentTree[2 * treeIndex + 1], segmentTree[2 * treeIndex + 2])
        return placed

    def numOfUnplacedFruits(self, fruits, baskets):
        n = len(fruits)
        segmentTree = [0] * (4 * n)
        self.buildSegmentTree(0, 0, n - 1, baskets, segmentTree)

        unplaced = 0
        for fruit in fruits:
            if not self.placeFruitInBasket(0, 0, n - 1, fruit, segmentTree):
                unplaced += 1

        return unplaced
