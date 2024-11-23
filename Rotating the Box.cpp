class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // a simple rotation question
        // so we can see constraints are less so easy bruteforce solution can work here
        int m = box.size();
        int n = box[0].size();
        for (int i = 0; i < m; i++) {
            // now for each row we can go in last element and check 
            // if its obstacle * we can't put stone on that or after that only before that
            // if its space we can swap stone with space simply
            int empty = n - 1; // as a reference for empty space
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    swap(box[i][j], box[i][empty]);
                    empty--;
                } else if (box[i][j] == '*') {
                    // cant use this space or after this so initialise empty before it
                    empty = j - 1;
                }
            }
        }
        vector<vector<char>> res(n, vector<char>(m));
        // now rotating it 90 degree, its simmple first row will be last column, second row will be
        // second last column and so on
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - i - 1] = box[i][j];
            }
        }
        return res;
    }
};
