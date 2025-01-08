class Solution {
public:

    bool isPrefixAndSuffix(string str1, string str2) {
        return (str2.size() >= str1.size() && str2.substr(0, str1.size()) == str1 && str2.substr(str2.size() - str1.size()) == str1);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) count++;
            }
        }
        return count;
    }
};
