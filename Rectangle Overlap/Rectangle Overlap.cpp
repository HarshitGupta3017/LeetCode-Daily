// Solution for Rectangle Overlap in CPP

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Two rectangles overlap iff they overlap on BOTH the x-axis and y-axis.
        // It's easier to check the negation: they DON'T overlap if one is
        // entirely to the left, right, above, or below the other.
        // We negate that condition to get the overlap check.

        // rec1 is entirely to the left of rec2 if rec1's right edge <= rec2's left edge.
        // rec1 is entirely to the right of rec2 if rec1's left edge >= rec2's right edge.
        // Same logic applies vertically.
        bool noXOverlap = rec1[2] <= rec2[0] || rec2[2] <= rec1[0];
        bool noYOverlap = rec1[3] <= rec2[1] || rec2[3] <= rec1[1];

        return !noXOverlap && !noYOverlap;
    }
};
