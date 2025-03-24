# Solution for Count Days Without Meetings in PY

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort(key = lambda x: x[0])
        res, merge_end = 0, 0
        for start, end in meetings:
            if start > merge_end + 1:
                res += (start - merge_end - 1)
            merge_end = max(merge_end, end)
        if merge_end < days:
            res += days - merge_end
        return res
