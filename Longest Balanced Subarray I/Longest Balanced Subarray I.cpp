// Solution for Longest Balanced Subarray I in CPP

class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();

        /*
            This will store the maximum length of any
            balanced subarray found so far.
        */
        int maxBalancedLength = 0;

        /*
            Fix the starting index of the subarray.
            We will expand the subarray to the right
            and keep track of distinct evens and odds.
        */
        for (int start = 0; start < n; start++) {

            /*
                We need to count DISTINCT even and odd numbers,
                not total count.

                unordered_set is perfect here because:
                - It automatically avoids duplicates
                - Insert and size operations are O(1) on average
            */
            unordered_set<int> distinctEven;
            unordered_set<int> distinctOdd;

            /*
                Extend the subarray from index `start` to `end`
                and update sets as we go.
            */
            for (int end = start; end < n; end++) {

                /*
                    Classify current number as even or odd
                    and insert it into the corresponding set.
                */
                if (nums[end] % 2 == 0) {
                    distinctEven.insert(nums[end]);
                } else {
                    distinctOdd.insert(nums[end]);
                }

                /*
                    A subarray is balanced if:
                    number of DISTINCT evens == number of DISTINCT odds
                */
                if (distinctEven.size() == distinctOdd.size()) {
                    maxBalancedLength = max(maxBalancedLength, end - start + 1);
                }
            }
        }

        return maxBalancedLength;
    }
};
