// Solution for Longest Unequal Adjacent Groups Subsequence I in CPP

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
