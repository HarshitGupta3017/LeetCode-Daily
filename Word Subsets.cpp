class Solution {
public:

    vector<int> getF(string word) {
        vector<int> freq(26, 0);
        for (char ch: word) {
            freq[ch - 'a']++;
        }
        return freq;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxF(26, 0);
        for (const string& word: words2) {
            vector<int> freq = getF(word);
            for (int i = 0; i < 26; i++) {
                maxF[i] = max(maxF[i], freq[i]);
            }
        }
        vector<string> res;
        for (const string& word: words1) {
            vector<int> freq = getF(word);
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxF[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) res.push_back(word);
        }
        return res;
    }
};
