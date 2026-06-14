# Solution for Maximum Twin Sum of a Linked List in PY

class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:

        vals = []

        while head:
            vals.append(head.val)
            head = head.next

        return max(vals[i] + vals[~i] for i in range(len(vals) // 2))
