class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // simple question 
        // we can just keep track of max element while traversing the array, if max element
        // is equal to current index that means till that all elements will be sorted or
        // need sorting so we will increase chunk size by 1
        int mx = 0, chunks = 0;
        for (int i = 0; i < arr.size(); i++) {
            mx = max(mx, arr[i]);
            if (mx == i) chunks++;
        }
        return chunks;
    }
};
