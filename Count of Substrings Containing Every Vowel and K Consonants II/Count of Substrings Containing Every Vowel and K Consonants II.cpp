// Solution for Count of Substrings Containing Every Vowel and K Consonants II in CPP

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> mp; // vowelsCount
        int n = word.size();
        vector<int> nextConsonant(n);
        int lastConsIdx = n; // consonant index
        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = lastConsIdx;
            if (vowels.find(word[i]) == vowels.end()) {
                lastConsIdx = i;
            }
        }
        int i = 0, j = 0, cons = 0;
        long long res = 0;
        while (j < n) {
            if (vowels.find(word[j]) != vowels.end()) {
                mp[word[j]]++;
            } else {
                cons++;
            }
            while (cons > k) {
                char ch = word[i];
                if (vowels.find(ch) != vowels.end()) {
                    mp[ch]--;
                    if (mp[ch] == 0) mp.erase(ch);
                } else {
                    cons--;
                }
                i++;
            }
            while (i < n && mp.size() == 5 && cons == k) {
                res += (nextConsonant[j] - j);
                char ch = word[i];
                if (vowels.find(ch) != vowels.end()) {
                    mp[ch]--;
                    if (mp[ch] == 0) mp.erase(ch);
                } else {
                    cons--;
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
