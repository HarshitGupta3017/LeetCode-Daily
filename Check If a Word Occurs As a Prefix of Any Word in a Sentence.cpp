class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream st(sentence);
        string word;
        int index = 1;
        while (st >> word) {
            if (word.substr(0, searchWord.size()) == searchWord) return index;
            index++;
        }
        return -1;
    }
};
