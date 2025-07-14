# Solution for Convert Binary Number in a Linked List to Integer in PY

class Solution:
    def getDecimalValue(self, head: Optional[ListNode]) -> int:
        decimalValue = 0
        while head:
            decimalValue = (decimalValue << 1) | head.val
            head = head.next
        return decimalValue
