// Solution for Minimum Distance Between Three Equal Elements II in CPP

class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        /*
        ============================================================
        Map structure:
        value -> {secondLastIndex, lastIndex}
        
        We only need last two occurrences to form triples
        ============================================================
        */
        unordered_map<int, pair<int, int>> lastTwoIndices;

        int minimumDistance = INT_MAX;

        /*
        ============================================================
        Traverse array
        ============================================================
        */
        for (int currentIndex = 0; currentIndex < nums.size(); currentIndex++) {

            int currentValue = nums[currentIndex];

            /*
            ------------------------------------------------------------
            If we have seen this value before
            ------------------------------------------------------------
            */
            if (lastTwoIndices.count(currentValue)) {

                int previousIndex = lastTwoIndices[currentValue].second;
                int secondPreviousIndex = lastTwoIndices[currentValue].first;

                /*
                --------------------------------------------------------
                If we already have 2 previous occurrences
                → we can form a triple:
                (secondPreviousIndex, previousIndex, currentIndex)
                --------------------------------------------------------
                */
                if (secondPreviousIndex != -1) {

                    /*
                    Distance = 2 * (k - i)
                    where:
                        i = secondPreviousIndex
                        k = currentIndex
                    */
                    minimumDistance = min(minimumDistance, 2 * (currentIndex - secondPreviousIndex));
                }

                /*
                --------------------------------------------------------
                Shift indices:
                old last → secondLast
                current → last
                --------------------------------------------------------
                */
                lastTwoIndices[currentValue] = {previousIndex, currentIndex};

            } else {

                /*
                First occurrence → no triple possible yet
                */
                lastTwoIndices[currentValue] = {-1, currentIndex};
            }
        }

        /*
        ============================================================
        If no valid triple found → return -1
        ============================================================
        */
        return (minimumDistance == INT_MAX) ? -1 : minimumDistance;
    }
};
