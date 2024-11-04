class Solution {
public:
    string compressedString(string word) {
        // ez question just need to count the characters until they make total of 9 
        // if they made count again with 0
        string comp = "";
        int i = 0;
        while (i < word.size()) {
            char curr = word[i];
            int count = 0;
            // if same character and count is less than 9 increment it
            while (i < word.size() && word[i] == curr && count < 9) {
                count++;
                i++;
            }
            // now add it to the comp when diff character
            comp += to_string(count) + curr;
        }
        return comp;
    }
};
