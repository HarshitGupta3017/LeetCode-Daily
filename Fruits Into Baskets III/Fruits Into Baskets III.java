// Solution for Fruits Into Baskets III in JAVA

class Solution {

    // Build the segment tree
    private void buildSegmentTree(int treeIndex, int left, int right, int[] baskets, int[] segmentTree) {
        if (left == right) {
            segmentTree[treeIndex] = baskets[left];
            return;
        }

        int mid = left + (right - left) / 2;

        buildSegmentTree(2 * treeIndex + 1, left, mid, baskets, segmentTree);
        buildSegmentTree(2 * treeIndex + 2, mid + 1, right, baskets, segmentTree);

        segmentTree[treeIndex] = Math.max(segmentTree[2 * treeIndex + 1], segmentTree[2 * treeIndex + 2]);
    }

    // Try to place fruit in the leftmost valid basket
    private boolean placeFruitInBasket(int treeIndex, int left, int right, int fruit, int[] segmentTree) {
        if (segmentTree[treeIndex] < fruit) return false;

        if (left == right) {
            segmentTree[treeIndex] = -1;
            return true;
        }

        int mid = left + (right - left) / 2;
        boolean placed;

        if (segmentTree[2 * treeIndex + 1] >= fruit) {
            placed = placeFruitInBasket(2 * treeIndex + 1, left, mid, fruit, segmentTree);
        } else {
            placed = placeFruitInBasket(2 * treeIndex + 2, mid + 1, right, fruit, segmentTree);
        }

        segmentTree[treeIndex] = Math.max(segmentTree[2 * treeIndex + 1], segmentTree[2 * treeIndex + 2]);
        return placed;
    }

    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n = fruits.length;
        int[] segmentTree = new int[4 * n];

        buildSegmentTree(0, 0, n - 1, baskets, segmentTree);

        int unplaced = 0;
        for (int fruit : fruits) {
            if (!placeFruitInBasket(0, 0, n - 1, fruit, segmentTree)) {
                unplaced++;
            }
        }

        return unplaced;
    }
}
