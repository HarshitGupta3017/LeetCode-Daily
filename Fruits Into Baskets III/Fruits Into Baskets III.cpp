// Solution for Fruits Into Baskets III in CPP

class Solution {
public:

    // Build the segment tree to store the max capacity in a range of baskets
    void buildSegmentTree(
        int treeIndex, int left, int right, 
        vector<int>& basketCapacities, vector<int>& segmentTree
    ) {
        // If this is a leaf node, store the basket capacity
        if (left == right) {
            segmentTree[treeIndex] = basketCapacities[left];
            return;
        }

        int mid = left + (right - left) / 2;

        // Recursively build the left and right subtrees
        buildSegmentTree(2 * treeIndex + 1, left, mid, basketCapacities, segmentTree);
        buildSegmentTree(2 * treeIndex + 2, mid + 1, right, basketCapacities, segmentTree);

        // Store the max capacity in the current segment
        segmentTree[treeIndex] = max(segmentTree[2 * treeIndex + 1], segmentTree[2 * treeIndex + 2]);
    }

    // Try to place the fruit into the leftmost valid basket using segment tree
    bool placeFruitInBasket(
        int treeIndex, int left, int right, 
        int& fruitQuantity, vector<int>& segmentTree
    ) {
        // If max capacity in this segment is less than the fruit quantity, cannot place here
        if (segmentTree[treeIndex] < fruitQuantity) {
            return false;
        }

        // If this is a leaf node (single basket), place the fruit and mark basket as used
        if (left == right) {
            segmentTree[treeIndex] = -1; // Mark basket as occupied
            return true;
        }

        int mid = left + (right - left) / 2;
        bool placedSuccessfully = false;

        // Always try placing in the leftmost valid basket first
        if (segmentTree[2 * treeIndex + 1] >= fruitQuantity) {
            placedSuccessfully = placeFruitInBasket(2 * treeIndex + 1, left, mid, fruitQuantity, segmentTree);
        } else {
            placedSuccessfully = placeFruitInBasket(2 * treeIndex + 2, mid + 1, right, fruitQuantity, segmentTree);
        }

        // Update the max capacity for the current segment after placement
        segmentTree[treeIndex] = max(segmentTree[2 * treeIndex + 1], segmentTree[2 * treeIndex + 2]);

        return placedSuccessfully;
    }

    // Main function to return the count of unplaced fruit types
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        // Segment tree size is 4 * n to accommodate worst-case storage
        vector<int> segmentTree(4 * n, 0);

        // Step 1: Build segment tree for basket capacities
        buildSegmentTree(0, 0, n - 1, baskets, segmentTree);

        int unplacedFruitCount = 0;

        // Step 2: Try to place each fruit in the earliest possible valid basket
        for (int& fruitQuantity : fruits) {
            bool wasPlaced = placeFruitInBasket(0, 0, n - 1, fruitQuantity, segmentTree);
            if (!wasPlaced) {
                unplacedFruitCount++;
            }
        }

        // Step 3: Return the count of fruits that couldn't be placed
        return unplacedFruitCount;
    }
};
