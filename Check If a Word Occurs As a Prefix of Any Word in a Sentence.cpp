class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Hello guyz, iam back with a simple question
        // we can simply make stream of words using istringstream - inbuilt method in cpp
        istringstream stream(sentence);
        string word;
        int index = 1; // in question its stated that there is 1-based indexing i.e. index starts with 1
        while (stream >> word) {
            // we can check each word now if it startswith searchWord or not
            if (word.substr(0, searchWord.size()) == searchWord) return index;
            index++;
        }
        return -1;
    }
};
