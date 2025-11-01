# Solution for Delete Nodes From Linked List Present in Array in PY

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        # Store all values to remove in a set for O(1) lookups
        values_to_remove = set(nums)

        # Dummy node to handle head removal easily
        dummy = ListNode(0, head)
        prev, curr = dummy, head

        # Traverse the linked list
        while curr:
            if curr.val in values_to_remove:
                prev.next = curr.next  # Skip current node
            else:
                prev = curr  # Keep current node
            curr = curr.next

        return dummy.next  # Return possibly new head
