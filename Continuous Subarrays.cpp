class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // so we need to find subarrays
        // we can use sliding window for that
        // and we need to take care of max and min val in subarray for satisfying the 
        // condition given in question, we can choose max and min and check their diff if 
        // less than 2 then its fine otherwise move from left
        // and for keeping track of max and min values we can use deque
        // deque for easy operations of push and pop from front and back
        int l = 0;
        deque<int> maxdeq, mindeq;
        long long total = 0;
        for (int r = 0; r < nums.size(); r++) {
            // if last element in mindeq is greater than current nums value then remove it
            // and add current one for keeping minimum values
            while (!mindeq.empty() && nums[mindeq.back()] > nums[r]) {
                mindeq.pop_back();
            }
            mindeq.push_back(r);
            // same for maxdeq for keeping maximum values
            while (!maxdeq.empty() && nums[maxdeq.back()] < nums[r]) {
                maxdeq.pop_back();
            }
            maxdeq.push_back(r);
            // if condition given in ques isn't satisfied
            while (nums[maxdeq.front()] - nums[mindeq.front()] > 2) {
                // move left pointer
                l++;
                // after moving left pointer check if any index less than that is present in 
                // deque, if yes then remove it as they are of no use now
                while (!mindeq.empty() && mindeq.front() < l) mindeq.pop_front();
                while (!maxdeq.empty() && maxdeq.front() < l) maxdeq.pop_front();
            }
            total += (r - l + 1);
        }
        return total;
    }
};
