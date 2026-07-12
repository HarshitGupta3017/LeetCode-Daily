// Solution for Rank Transform of an Array in CPP

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Work on a sorted copy so the original order is preserved for the output pass.
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());

        // Map each unique value to its rank.
        // Iterating the sorted copy means the first time we see a value is always
        // at its correct rank position — duplicates are simply skipped.
        unordered_map<int, int> rankOf;
        int nextRank = 1;

        for (int num : sorted) {
            if (!rankOf.count(num))
                rankOf[num] = nextRank++;
        }

        // Replace each original element with its precomputed rank.
        vector<int> result(arr.size());
        for (int i = 0; i < (int)arr.size(); i++)
            result[i] = rankOf[arr[i]];

        return result;
    }
};
