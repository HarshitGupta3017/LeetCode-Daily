// Solution for Rotate List in CPP

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge cases: empty list, single node, or no rotation needed
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Find length of list and last node
        ListNode* tail = head;
        int length = 1;

        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Form a circular linked list
        tail->next = head;

        // Step 3: Normalize k (avoid unnecessary full rotations)
        k = k % length;

        // If no effective rotation, break circle and return head
        if (k == 0) {
            tail->next = nullptr;
            return head;
        }

        // Step 4: Find new tail position
        // New tail will be at (length - k - 1)th node
        int stepsToNewTail = length - k - 1;

        ListNode* newTail = head;
        for (int step = 0; step < stepsToNewTail; step++) {
            newTail = newTail->next;
        }

        // Step 5: Set new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
