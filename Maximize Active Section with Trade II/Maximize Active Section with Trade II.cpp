// Solution for Maximize Active Section with Trade II in CPP

// ---------------------------------------------------------------------------
// Segment tree for range-maximum queries over an array of pair sums.
// Each node stores the maximum value in its subtree.
// ---------------------------------------------------------------------------

void buildSegTree(int node, int nodeL, int nodeR, int segTree[], int arr[]) {
    if (nodeL == nodeR) {
        segTree[node] = arr[nodeL];
        return;
    }
    int mid = nodeL + (nodeR - nodeL) / 2;
    buildSegTree(2 * node + 1, nodeL, mid,       segTree, arr);
    buildSegTree(2 * node + 2, mid + 1, nodeR,   segTree, arr);
    // Each internal node stores the max of its two children so any range
    // query can be answered in O(log n) by combining subtree results.
    segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
}

int* buildSegmentTree(int arr[], int n) {
    int* segTree = new int[4 * n];
    buildSegTree(0, 0, n - 1, segTree, arr);
    return segTree;
}

int querySegTree(int qL, int qR, int node, int nodeL, int nodeR, int segTree[]) {
    // No overlap — return identity for max so it doesn't affect the result.
    if (nodeL > qR || nodeR < qL) return INT_MIN;
    // Full containment — this node's stored max covers the entire query range.
    if (nodeL >= qL && nodeR <= qR) return segTree[node];

    int mid = nodeL + (nodeR - nodeL) / 2;
    return max(querySegTree(qL, qR, 2 * node + 1, nodeL, mid,     segTree),
               querySegTree(qL, qR, 2 * node + 2, mid + 1, nodeR, segTree));
}

int rangeMax(int segTree[], int n, int l, int r) {
    return querySegTree(l, r, 0, 0, n - 1, segTree);
}

// ---------------------------------------------------------------------------

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int totalActive = count(s.begin(), s.end(), '1');

        // Collect the start and end indices of every contiguous '0'-block.
        // The augmented '1's at both ends (per problem note) guarantee that
        // every '0'-block is surrounded by '1's, so any block is trade-eligible.
        vector<int> zeroStart, zeroEnd;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;
                zeroStart.push_back(start);
                zeroEnd.push_back(i - 1);
            } else {
                i++;
            }
        }

        int numBlocks = zeroStart.size();

        // With fewer than 2 zero-blocks there is no adjacent pair to trade,
        // so every query answer is just the count of existing '1's.
        if (numBlocks < 2)
            return vector<int>(queries.size(), totalActive);

        // blockLen[k] = length of the k-th zero-block.
        vector<int> blockLen(numBlocks);
        for (int k = 0; k < numBlocks; k++)
            blockLen[k] = zeroEnd[k] - zeroStart[k] + 1;

        // pairSum[k] = blockLen[k] + blockLen[k+1]: the gain from merging the
        // k-th and (k+1)-th zero-blocks via one trade (sacrificing the '1'-block
        // between them). There are numBlocks-1 such adjacent pairs.
        int numPairs = numBlocks - 1;
        vector<int> pairSum(numPairs);
        for (int k = 0; k < numPairs; k++)
            pairSum[k] = blockLen[k] + blockLen[k + 1];

        // Build a sparse segment tree over pairSum for O(log n) range-max queries.
        int* segTree = buildSegmentTree(pairSum.data(), numPairs);

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            // Find the first zero-block whose end is >= l (leftmost block touching [l,r]).
            int firstBlock = (int)(lower_bound(zeroEnd.begin(), zeroEnd.end(), l) - zeroEnd.begin());

            // Find the last zero-block whose start is <= r (rightmost block touching [l,r]).
            int lastBlock  = (int)(upper_bound(zeroStart.begin(), zeroStart.end(), r) - zeroStart.begin()) - 1;

            int maxGain = 0;

            if (firstBlock < lastBlock) {
                // At least two zero-blocks fall (even partially) within [l, r].
                // The first and last blocks may be clipped by the query boundary,
                // so we compute their effective lengths within [l, r] separately.
                int firstEffLen = zeroEnd[firstBlock]   - max(zeroStart[firstBlock], l) + 1;
                int lastEffLen  = min(zeroEnd[lastBlock], r) - zeroStart[lastBlock]     + 1;

                if (lastBlock - firstBlock == 1) {
                    // Exactly two blocks — their combined effective length is the only option.
                    maxGain = firstEffLen + lastEffLen;
                } else {
                    // Three or more blocks. The best trade is one of:
                    // (a) first (clipped) block + its full right neighbour,
                    // (b) last (clipped) block  + its full left neighbour,
                    // (c) any fully interior adjacent pair — answered by a range-max query.
                    int gainFromLeft   = firstEffLen + blockLen[firstBlock + 1];
                    int gainFromRight  = blockLen[lastBlock - 1] + lastEffLen;
                    // Interior pairs occupy pairSum indices [firstBlock+1 .. lastBlock-2].
                    int gainFromMiddle = rangeMax(segTree, numPairs, firstBlock + 1, lastBlock - 2);
                    maxGain = max({gainFromLeft, gainFromRight, gainFromMiddle});
                }
            }

            answer.push_back(totalActive + maxGain);
        }

        delete[] segTree;
        return answer;
    }
};
