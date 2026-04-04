# Solution for Decode the Slanted Ciphertext in PY

class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        total_chars = len(encodedText)

        # If only one row → no transformation happened
        if rows == 1:
            return encodedText

        # STEP 1: Calculate number of columns
        cols = total_chars // rows

        original_text = []

        # STEP 2: Traverse diagonals
        for start_col in range(cols):
            index = start_col

            while index < total_chars:
                original_text.append(encodedText[index])

                # Move diagonally → next row & next column
                index += (cols + 1)

        # STEP 3: Remove trailing spaces
        return ''.join(original_text).rstrip()
