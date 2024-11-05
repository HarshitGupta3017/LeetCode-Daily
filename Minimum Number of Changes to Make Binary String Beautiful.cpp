class Solution {
public:
    int minChanges(string s) {
        // we are given string is of even length and can make any number of even pairs as limit isn't 
        // mentioned, we just need to count the total changes we need to do
        // so we can compare in pair of 2 if both are 0 or 1 no change need but if they are different
        // then increase the count
        int count = 0;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != s[i + 1]) count++;
        }
        return count;
    }
};
