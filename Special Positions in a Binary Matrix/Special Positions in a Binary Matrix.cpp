// Solution for Special Positions in a Binary Matrix in CPP

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        /*
            m = number of rows
            n = number of columns
        */
        int totalRows = mat.size();
        int totalColumns = mat[0].size();

        /*
            rowOnesCount[i]  = number of 1s present in row i
            columnOnesCount[j] = number of 1s present in column j

            These help us quickly verify whether a '1'
            is the only one in its row and column.
        */
        vector<int> rowOnesCount(totalRows, 0);
        vector<int> columnOnesCount(totalColumns, 0);

        /*
            First Pass:
            Count how many 1s exist in each row and column.
        */
        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalColumns; col++) {

                if (mat[row][col] == 1) {
                    rowOnesCount[row]++;
                    columnOnesCount[col]++;
                }
            }
        }

        /*
            Second Pass:
            A position (row, col) is special if:

            1) mat[row][col] == 1
            2) rowOnesCount[row] == 1
            3) columnOnesCount[col] == 1
        */
        int specialPositionsCount = 0;

        for (int row = 0; row < totalRows; row++) {
            for (int col = 0; col < totalColumns; col++) {

                /*
                    Skip immediately if current cell is 0,
                    since special position must be 1.
                */
                if (mat[row][col] == 0)
                    continue;

                /*
                    Check if this '1' is the only 1
                    in its row and column.
                */
                if (rowOnesCount[row] == 1 && columnOnesCount[col] == 1) {
                    specialPositionsCount++;
                }
            }
        }

        return specialPositionsCount;
    }
};
