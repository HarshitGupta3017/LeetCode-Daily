class Solution {
public:
    int minSwaps(string s) {
        int check = 0, swaps = 0;
        for (const char& c: s) {
            if (c == '[') check++;
            else check--;
            if (check < 0) {
                swaps++;
                check = 1;
            }
        }
        return swaps;
    }
};
