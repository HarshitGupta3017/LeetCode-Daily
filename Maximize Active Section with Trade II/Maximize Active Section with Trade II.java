// Solution for Maximize Active Section with Trade II in JAVA

class Solution {

    // ---------------------------------------------------------------------------
    // Segment tree for range maximum queries.
    // ---------------------------------------------------------------------------

    private void buildSegTree(int node, int nodeL, int nodeR, int[] segTree, int[] arr) {
        if (nodeL == nodeR) {
            segTree[node] = arr[nodeL];
            return;
        }

        int mid = nodeL + (nodeR - nodeL) / 2;
        buildSegTree(2 * node + 1, nodeL, mid, segTree, arr);
        buildSegTree(2 * node + 2, mid + 1, nodeR, segTree, arr);

        segTree[node] = Math.max(segTree[2 * node + 1], segTree[2 * node + 2]);
    }

    private int[] buildSegmentTree(int[] arr) {
        int[] segTree = new int[4 * arr.length];
        buildSegTree(0, 0, arr.length - 1, segTree, arr);
        return segTree;
    }

    private int querySegTree(int qL, int qR, int node, int nodeL, int nodeR, int[] segTree) {
        if (nodeL > qR || nodeR < qL)
            return Integer.MIN_VALUE;

        if (nodeL >= qL && nodeR <= qR)
            return segTree[node];

        int mid = nodeL + (nodeR - nodeL) / 2;

        return Math.max(
                querySegTree(qL, qR, 2 * node + 1, nodeL, mid, segTree),
                querySegTree(qL, qR, 2 * node + 2, mid + 1, nodeR, segTree));
    }

    private int rangeMax(int[] segTree, int n, int l, int r) {
        return querySegTree(l, r, 0, 0, n - 1, segTree);
    }

    public List<Integer> maxActiveSectionsAfterTrade(String s, int[][] queries) {

        int n = s.length();

        int totalActive = 0;
        for (char c : s.toCharArray())
            if (c == '1')
                totalActive++;

        List<Integer> zeroStart = new ArrayList<>();
        List<Integer> zeroEnd = new ArrayList<>();

        int i = 0;
        while (i < n) {
            if (s.charAt(i) == '0') {
                int start = i;
                while (i < n && s.charAt(i) == '0')
                    i++;
                zeroStart.add(start);
                zeroEnd.add(i - 1);
            } else {
                i++;
            }
        }

        int numBlocks = zeroStart.size();

        List<Integer> ans = new ArrayList<>();

        if (numBlocks < 2) {
            for (int k = 0; k < queries.length; k++)
                ans.add(totalActive);
            return ans;
        }

        int[] blockLen = new int[numBlocks];
        for (int k = 0; k < numBlocks; k++)
            blockLen[k] = zeroEnd.get(k) - zeroStart.get(k) + 1;

        int numPairs = numBlocks - 1;
        int[] pairSum = new int[numPairs];

        for (int k = 0; k < numPairs; k++)
            pairSum[k] = blockLen[k] + blockLen[k + 1];

        int[] segTree = buildSegmentTree(pairSum);

        for (int[] q : queries) {

            int l = q[0], r = q[1];

            int firstBlock = lowerBound(zeroEnd, l);
            int lastBlock = upperBound(zeroStart, r) - 1;

            int maxGain = 0;

            if (firstBlock < lastBlock) {

                int firstEffLen = zeroEnd.get(firstBlock)
                        - Math.max(zeroStart.get(firstBlock), l) + 1;

                int lastEffLen = Math.min(zeroEnd.get(lastBlock), r)
                        - zeroStart.get(lastBlock) + 1;

                if (lastBlock - firstBlock == 1) {

                    maxGain = firstEffLen + lastEffLen;

                } else {

                    int gainLeft = firstEffLen + blockLen[firstBlock + 1];
                    int gainRight = blockLen[lastBlock - 1] + lastEffLen;

                    int gainMiddle = rangeMax(segTree, numPairs,
                            firstBlock + 1,
                            lastBlock - 2);

                    maxGain = Math.max(Math.max(gainLeft, gainRight), gainMiddle);
                }
            }

            ans.add(totalActive + maxGain);
        }

        return ans;
    }

    private int lowerBound(List<Integer> arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr.get(mid) < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    private int upperBound(List<Integer> arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr.get(mid) <= target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
}
