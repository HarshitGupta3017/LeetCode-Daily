class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // just store banned vector in a set for easy access
        unordered_set<int> st(banned.begin(), banned.end());
        int count = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            // check if number is present in set than dont take it
            if (st.count(i)) continue;
            // if sum + curr num is greater than maxSum then break it
            if (sum + i > maxSum) break;
            // else add in sum and increase count
            sum += i;
            count++;
        }
        return count;
    }
};
