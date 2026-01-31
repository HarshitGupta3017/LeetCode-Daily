// Solution for Find Smallest Letter Greater Than Target in CPP

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = upper_bound(letters.begin(), letters.end(), target);
        return (it == letters.end()) ? letters[0] : *it;
    }
};
