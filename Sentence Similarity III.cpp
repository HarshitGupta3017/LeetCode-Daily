class Solution {
public:

    vector<string> splitwords(string& s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) words.push_back(word);
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = splitwords(sentence1);
        vector<string> words2 = splitwords(sentence2);
        int left = 0, right = 0, n1 = words1.size(), n2 = words2.size();
        while (left < n1 && left < n2 && words1[left] == words2[left]) left++;
        while (right < n1 - left && right < n2 - left && words1[n1 - right - 1] == words2[n2 - right - 1]) right++;
        return left + right == min(n1, n2);
    }
};
