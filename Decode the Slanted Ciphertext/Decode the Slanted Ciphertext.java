// Solution for Decode the Slanted Ciphertext in JAVA

class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        int totalChars = encodedText.length();

        // If only one row → no transformation happened
        if (rows == 1) return encodedText;

        // STEP 1: Calculate number of columns
        int cols = totalChars / rows;

        StringBuilder originalText = new StringBuilder();

        // STEP 2: Traverse diagonals
        for (int startCol = 0; startCol < cols; startCol++) {

            int index = startCol;

            while (index < totalChars) {
                originalText.append(encodedText.charAt(index));

                // Move diagonally → next row & next column
                index += (cols + 1);
            }
        }

        // STEP 3: Remove trailing spaces
        int end = originalText.length() - 1;
        while (end >= 0 && originalText.charAt(end) == ' ') {
            end--;
        }

        return originalText.substring(0, end + 1);
    }
}
