// Solution for Largest Submatrix With Rearrangements in CPP

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        int totalRows = matrix.size();
        int totalCols = matrix[0].size();

        /*
            Stores the maximum area of a submatrix of 1s.
        */
        int maximumArea = 0;

        /*
            Stores (height, columnIndex) for previous row.
            Only columns that contributed to valid submatrices are stored.
        */
        vector<pair<int, int>> previousRowHeights;

        /*
            Process each row one by one.
        */
        for (int row = 0; row < totalRows; row++) {

            /*
                Will store updated heights for current row.
            */
            vector<pair<int, int>> currentRowHeights;

            /*
                Tracks which columns are already processed
                from previous row.
            */
            vector<bool> columnVisited(totalCols, false);

            /*
                Step 1:
                Extend heights from previous row where possible.

                If a column had height in previous row AND current cell is 1,
                we increase height by 1.
            */
            for (const auto& [previousHeight, columnIndex] : previousRowHeights) {

                if (matrix[row][columnIndex] == 1) {

                    currentRowHeights.push_back({previousHeight + 1, columnIndex});

                    columnVisited[columnIndex] = true;
                }
            }

            /*
                Step 2:
                Handle new columns where current cell is 1
                but were not part of previous row heights.

                These start with height = 1.
            */
            for (int col = 0; col < totalCols; col++) {

                if (!columnVisited[col] && matrix[row][col] == 1) {

                    currentRowHeights.push_back({1, col});
                }
            }

            /*
                Important Observation:

                currentRowHeights is already in a valid order where
                heights are non-increasing or nearly arranged optimally.

                Why?

                - Previous row was already in optimal order
                - We extend those heights first (larger heights stay first)
                - New height=1 entries come later

                So we can directly compute areas without sorting.
            */

            /*
                Step 3:
                Compute max area using current heights.

                width = i + 1 (taking first i+1 columns)
                height = currentRowHeights[i].first
            */
            for (int i = 0; i < currentRowHeights.size(); i++) {

                int width = i + 1;
                int height = currentRowHeights[i].first;

                maximumArea = max(maximumArea, width * height);
            }

            /*
                Step 4:
                Move current row heights to previous for next iteration.
            */
            previousRowHeights = currentRowHeights;
        }

        return maximumArea;
    }
};
