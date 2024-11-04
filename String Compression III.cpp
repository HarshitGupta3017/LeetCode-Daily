class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        while (i < word.size()) {
            char curr = word[i];
            int count = 0;
            while (i < word.size() && word[i] == curr && count < 9) {
                count++;
                i++;
            }
            comp += to_string(count) + curr;
        }
        return comp;
    }
};
