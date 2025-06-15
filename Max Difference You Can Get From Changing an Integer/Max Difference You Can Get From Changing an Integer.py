# Solution for Max Difference You Can Get From Changing an Integer in PY

class Solution:
    def maxDiff(self, num: int) -> int:
        str_num = str(num)
        for ch in str_num:
            if ch != '9':
                str_max = str_num.replace(ch, '9')
                break
        else:
            str_max = str_num

        for i in range(len(str_num)):
            ch = str_num[i]
            if i == 0 and ch != '1':
                str_min = str_num.replace(ch, '1')
                break
            elif ch != '0' and ch != str_num[0]:
                str_min = str_num.replace(ch, '0')
                break
        else:
            str_min = str_num 
            
        return int(str_max) - int(str_min)
