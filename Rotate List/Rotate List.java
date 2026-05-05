// Solution for Rotate List in JAVA

class Solution {
    public ListNode rotateRight(ListNode head, int k) {

        // Edge cases
        if (head == null || head.next == null || k == 0)
            return head;

        // Step 1: Find length and tail
        ListNode tail = head;
        int length = 1;

        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        // Step 2: Make it circular
        tail.next = head;

        // Step 3: Normalize k
        k = k % length;

        if (k == 0) {
            tail.next = null;
            return head;
        }

        // Step 4: Find new tail
        int stepsToNewTail = length - k - 1;
        ListNode newTail = head;

        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail.next;
        }

        // Step 5: Break circle
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}
