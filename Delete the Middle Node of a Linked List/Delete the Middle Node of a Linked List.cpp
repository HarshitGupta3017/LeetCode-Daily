// Solution for Delete the Middle Node of a Linked List in CPP

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // A list with 0 or 1 nodes has no valid middle to keep after deletion.
        if (!head || !head->next)
            return nullptr;

        // We use a fast/slow pointer approach to find the middle in one pass.
        // fast moves two steps for every one step slow moves, so when fast
        // reaches the end, slow is exactly at the middle node.
        // prev trails one step behind slow so we can rewire the list around
        // the middle node without a second traversal.
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is now the middle node. Bypass it by linking its predecessor
        // directly to its successor, then free the memory.
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
