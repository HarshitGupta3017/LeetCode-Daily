// Solution for Longest Palindrome by Concatenating Two Letter Words in CPP

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (const auto& word: words) {
            mp[word]++;
        }
        int res = 0;
        bool centerUsed = false;
        for (const auto& word: words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word != rev) {
                if (mp[word] > 0 && mp[rev] > 0) {
                    mp[word]--;
                    mp[rev]--;
                    res += 4;
                }
            } else {
                if (mp[word] >= 2) {
                    mp[word] -= 2;
                    res += 4;
                } else if (mp[word] == 1 && !centerUsed) {
                    mp[word]--;
                    centerUsed = true;
                    res += 2;
                }
            }
        }
        return res;
    }
};
