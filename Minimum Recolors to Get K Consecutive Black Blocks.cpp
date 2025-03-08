class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), i = 0, j = 0;
        int res = k, W = 0;
        while (j < n) {
            if (blocks[j] == 'W') W++;
            if (j - i + 1 == k) {
                res = min(res, W);
                if (blocks[i] == 'W') W--;
                i++;
            }
            j++;
        }
        return res;
    }
};
