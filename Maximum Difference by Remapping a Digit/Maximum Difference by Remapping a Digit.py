# Solution for Maximum Difference by Remapping a Digit in PY

class Solution:
    def minMaxDifference(self, num: int) -> int:
        str_num = str(num)
        
        # ----------- Create maximum number -----------
        # Find first digit that is not '9' and replace all its occurrences with '9'
        for ch in str_num:
            if ch != '9':
                str_max = str_num.replace(ch, '9')
                break
        else:
            str_max = str_num  # All digits are '9', no replacement needed

        # ----------- Create minimum number -----------
        # Replace all occurrences of the first digit with '0'
        str_min = str_num.replace(str_num[0], '0')

        # Return the difference
        return int(str_max) - int(str_min)
