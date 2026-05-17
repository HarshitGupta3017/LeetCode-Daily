// Solution for Jump Game III in CPP

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        // Invalid index or already visited index
        if (start < 0 ||
            start >= arr.size() ||
            arr[start] < 0) {

            return false;
        }

        // Reached an index containing value 0
        if (arr[start] == 0) {

            return true;
        }

        // Store current jump distance
        int jumpDistance = arr[start];

        // Mark current index as visited
        // by converting value to negative
        arr[start] = -1;

        // Try both possible jumps:
        // forward and backward
        return canReach(arr, start + jumpDistance) ||
               canReach(arr, start - jumpDistance);
    }
};
