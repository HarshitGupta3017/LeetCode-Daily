# Solution for Count the Number of Special Characters II in PY

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:

        last_lowercase_index = [-1] * 26
        first_uppercase_index = [-1] * 26

        for index, current_character in enumerate(word):

            if current_character.islower():

                last_lowercase_index[ord(current_character) - ord('a')] = index

            else:

                char_index = ord(current_character) - ord('A')

                if first_uppercase_index[char_index] == -1:

                    first_uppercase_index[char_index] = index

        special_character_count = 0

        for alphabet_index in range(26):

            if (last_lowercase_index[alphabet_index] != -1 and
                first_uppercase_index[alphabet_index] != -1 and
                last_lowercase_index[alphabet_index] < first_uppercase_index[alphabet_index]):

                special_character_count += 1

        return special_character_count
