# Solution for Words Within Two Edits of Dictionary in PY

class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        matching_words = []

        for query_word in queries:
            for dict_word in dictionary:
                mismatch_count = 0

                for i in range(len(query_word)):
                    if query_word[i] != dict_word[i]:
                        mismatch_count += 1

                    if mismatch_count > 2:
                        break

                if mismatch_count <= 2:
                    matching_words.append(query_word)
                    break

        return matching_words
