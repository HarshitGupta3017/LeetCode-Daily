class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // simple question 
        // just traverse both strings and check if both characters match or char in str1 after cyclic
        // increment matches str2 or not
        // if at last all are matched return true
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j] || str1[i] + 1 == str2[j] || str1[i] - 25 == str2[j]) j++;
            i++;
        }
        return j == str2.size();
    }
};
