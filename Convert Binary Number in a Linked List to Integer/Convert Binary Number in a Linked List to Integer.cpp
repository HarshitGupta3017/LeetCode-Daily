// Solution for Convert Binary Number in a Linked List to Integer in CPP

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimalValue = 0;

        // Traverse the linked list node by node
        while (head) {
            // Left shift the current result (equivalent to multiplying by 2)
            // and add the current node's binary digit
            decimalValue = (decimalValue << 1) | head->val;

            // Move to the next node
            head = head->next;
        }

        // Final result contains the decimal value of the binary number
        return decimalValue;
    }
};
