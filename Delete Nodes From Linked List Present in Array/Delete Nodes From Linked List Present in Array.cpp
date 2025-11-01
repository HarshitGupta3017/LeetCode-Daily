// Solution for Delete Nodes From Linked List Present in Array in CPP

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Store all values to be removed in a set for quick lookup
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());
        
        // Create a dummy node to simplify edge cases (like removing the head node)
        ListNode* dummy = new ListNode(0, head);
        
        // 'prev' tracks the previous valid node, 'curr' iterates through the list
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        // Traverse through the linked list
        while (curr) {
            // If the current node's value exists in the set, skip this node
            if (valuesToRemove.count(curr->val)) {
                prev->next = curr->next;
            } 
            // Otherwise, move 'prev' forward as this node remains in the list
            else {
                prev = curr;
            }
            // Move to the next node
            curr = curr->next;
        }
        
        // Return the new head (which may have changed if the old head was removed)
        return dummy->next;
    }
};
