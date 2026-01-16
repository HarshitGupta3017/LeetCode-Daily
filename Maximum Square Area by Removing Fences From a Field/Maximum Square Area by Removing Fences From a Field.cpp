// Solution for Maximum Square Area by Removing Fences From a Field in CPP

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        const int MOD = 1e9 + 7;

        // Add boundary fences (cannot be removed)
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        // Sort fence positions
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        /*
            Store all possible vertical distances
            formed by choosing any two horizontal fences
        */
        unordered_set<int> possibleHeights;
        int horizontalCount = hFences.size();

        for (int i = 0; i < horizontalCount; i++) {
            for (int j = i + 1; j < horizontalCount; j++) {
                possibleHeights.insert(hFences[j] - hFences[i]);
            }
        }

        /*
            Check vertical fence distances
            and find the largest common distance
        */
        int maxSquareSide = 0;
        int verticalCount = vFences.size();

        for (int i = 0; i < verticalCount; i++) {
            for (int j = i + 1; j < verticalCount; j++) {
                int width = vFences[j] - vFences[i];
                if (possibleHeights.count(width)) {
                    maxSquareSide = max(maxSquareSide, width);
                }
            }
        }

        // If no square possible
        if (maxSquareSide == 0) return -1;

        // Return area modulo 1e9 + 7
        long long area = 1LL * maxSquareSide * maxSquareSide;
        return area % MOD;
    }
};
