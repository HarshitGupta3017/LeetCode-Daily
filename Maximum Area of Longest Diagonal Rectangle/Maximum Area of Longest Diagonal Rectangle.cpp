// Solution for Maximum Area of Longest Diagonal Rectangle in CPP

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiag = 0, maxArea = 0;
        int n = dimensions.size();
        for (int i = 0; i < n; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int diag = l*l + w*w;
            int area = l * w;
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
