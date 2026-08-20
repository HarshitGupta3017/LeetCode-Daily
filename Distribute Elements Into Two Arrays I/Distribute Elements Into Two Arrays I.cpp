// Solution for Distribute Elements Into Two Arrays I in CPP

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        // We build arr1 from the front and arr2 from the back of result[],
        // so both arrays share one pre-allocated output buffer without extra copies.
        // arr2 is stored in reverse order at the tail; we fix that with a final reverse.
        vector<int> result(n);

        // First operation: nums[0] → arr1 (front), nums[1] → arr2 (back).
        result[0] = nums[0];
        result[n - 1] = nums[1];

        int frontTail = 0;      // index of arr1's last element (grows rightward)
        int backTail  = n - 1;  // index of arr2's last element (grows leftward)

        for (int i = 2; i < n; i++) {
            if (result[frontTail] > result[backTail]) {
                // arr1's last element is larger → append nums[i] to arr1.
                result[++frontTail] = nums[i];
            } else {
                // arr2's last element is >= arr1's → append nums[i] to arr2.
                result[--backTail] = nums[i];
            }
        }

        // arr2 was filled right-to-left, so its logical order is currently reversed.
        // Reversing the tail segment [backTail, n-1] restores the correct order.
        reverse(result.begin() + backTail, result.end());

        return result;
    }
};
