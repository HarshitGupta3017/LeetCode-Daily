// Solution for Delete the Middle Node of a Linked List in JAVA

class Solution {
    public ListNode deleteMiddle(ListNode head) {

        if (head == null || head.next == null)
            return null;

        ListNode prev = null, slow = head, fast = head;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = slow.next;

        return head;
    }
}
