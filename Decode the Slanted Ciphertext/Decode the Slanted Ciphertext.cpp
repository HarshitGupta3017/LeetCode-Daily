// Solution for Decode the Slanted Ciphertext in CPP

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int totalChars = encodedText.size();

        // If only one row → no transformation happened
        if (rows == 1) return encodedText;

        /*
        ============================================================
        STEP 1: Calculate number of columns
        ============================================================

        Matrix size = rows x cols
        → cols = totalChars / rows
        */
        int cols = totalChars / rows;

        string originalText;

        /*
        ============================================================
        STEP 2: Traverse diagonals
        ============================================================

        IMPORTANT IDEA:
        Original text was filled diagonally (top-left → bottom-right)

        So to decode:
        → Start from each column of FIRST row
        → Move diagonally down-right
        */

        for (int startCol = 0; startCol < cols; startCol++) {

            /*
                Start from (row = 0, col = startCol)

                In 1D string:
                index = row * cols + col

                Moving diagonally:
                row++, col++
                → index increases by (cols + 1)
            */
            int index = startCol;

            while (index < totalChars) {
                originalText.push_back(encodedText[index]);

                // Move diagonally → next row & next column
                index += (cols + 1);
            }
        }

        /*
        ============================================================
        STEP 3: Remove trailing spaces
        ============================================================

        Because matrix was padded with spaces
        */
        while (!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }

        return originalText;
    }
};
