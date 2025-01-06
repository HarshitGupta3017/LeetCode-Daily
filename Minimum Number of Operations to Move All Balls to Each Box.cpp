class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        int cumVal = 0, cumValSum = 0;
        for (int i = 0; i < n; i++) {
            res[i] = cumValSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumValSum += cumVal;
        }
        cumVal = 0, cumValSum = 0;
        for (int i = n - 1; i >= 0; i--) {
            res[i] += cumValSum;
            cumVal += boxes[i] == '0' ? 0 : 1;
            cumValSum += cumVal;
        }
        return res;
    }
};
