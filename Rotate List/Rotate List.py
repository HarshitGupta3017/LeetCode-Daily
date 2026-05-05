# Solution for Rotate List in PY

class Solution:
    def rotateRight(self, head, k):

        # Edge cases
        if not head or not head.next or k == 0:
            return head

        # Step 1: Find length and tail
        tail = head
        length = 1

        while tail.next:
            tail = tail.next
            length += 1

        # Step 2: Make circular
        tail.next = head

        # Step 3: Normalize k
        k %= length

        if k == 0:
            tail.next = None
            return head

        # Step 4: Find new tail
        steps = length - k - 1
        new_tail = head

        for _ in range(steps):
            new_tail = new_tail.next

        # Step 5: Break circle
        new_head = new_tail.next
        new_tail.next = None

        return new_head
