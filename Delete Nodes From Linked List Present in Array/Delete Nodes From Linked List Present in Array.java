// Solution for Delete Nodes From Linked List Present in Array in JAVA

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        // Store all values to remove in a set for O(1) lookups
        Set<Integer> valuesToRemove = new HashSet<>();
        for (int num : nums) {
            valuesToRemove.add(num);
        }

        // Dummy node to simplify edge cases
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        ListNode curr = head;

        // Traverse linked list
        while (curr != null) {
            if (valuesToRemove.contains(curr.val)) {
                prev.next = curr.next; // Skip node
            } else {
                prev = curr; // Keep node
            }
            curr = curr.next;
        }

        return dummy.next; // Return possibly updated head
    }
}
