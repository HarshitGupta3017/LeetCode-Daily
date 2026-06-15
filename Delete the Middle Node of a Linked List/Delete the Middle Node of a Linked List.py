# Solution for Delete the Middle Node of a Linked List in PY

class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if not head or not head.next:
            return None

        prev, slow, fast = None, head, head

        while fast and fast.next:
            prev, slow, fast = slow, slow.next, fast.next.next

        prev.next = slow.next

        return head
