// Solution for Bitwise ORs of Subarrays in CPP

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prevOrs;     // Stores OR results of subarrays ending at previous index
        unordered_set<int> currOrs;     // Stores OR results of subarrays ending at current index
        unordered_set<int> distinctOrs; // Stores all distinct OR values across all subarrays

        for (int i = 0; i < arr.size(); i++) {
            // Start a new set for current index
            currOrs.insert(arr[i]);  // Start a new subarray from current element
            distinctOrs.insert(arr[i]);

            // Extend subarrays from previous index and OR with current element
            for (const int& prevVal : prevOrs) {
                int newOr = prevVal | arr[i];
                currOrs.insert(newOr);
                distinctOrs.insert(newOr);
            }

            // Move current ORs to prevOrs for next iteration
            prevOrs = currOrs;
            currOrs.clear();
        }

        return distinctOrs.size(); // Total number of unique OR results
    }
};
