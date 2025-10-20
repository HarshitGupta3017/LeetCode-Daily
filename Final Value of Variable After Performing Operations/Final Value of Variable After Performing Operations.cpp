// Solution for Final Value of Variable After Performing Operations in CPP

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const auto& o: operations) x = (o[1] == '-') ? x - 1 : x + 1;
        return x;
    }
};
