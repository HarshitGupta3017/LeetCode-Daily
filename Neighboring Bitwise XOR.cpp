class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        auto isValid = [&](int start) {
            vector<int> original(n);
            original[0] = start;
            for (int i = 1; i < n; i++) {
                original[i] = derived[i - 1] ^ original[i - 1];
            }  
            return (original[n - 1] ^ original[0]) == derived[n - 1];
        };
        return isValid(0) || isValid(1);
    }
};
