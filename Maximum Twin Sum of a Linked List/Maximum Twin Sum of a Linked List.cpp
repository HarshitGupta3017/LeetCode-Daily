// Solution for Maximum Twin Sum of a Linked List in CPP

class Solution {
public:
    int pairSum(ListNode* head) {
        // Collect all values into a vector so we can access both ends simultaneously.
        // A linked list only supports forward traversal, so random access via index
        // is not possible without this linearisation step.
        vector<int> vals;
        for (ListNode* curr = head; curr; curr = curr->next)
            vals.push_back(curr->val);

        int maxTwinSum = 0;

        // Twin pairs are (0, n-1), (1, n-2), ..., meeting in the middle.
        // We walk both ends inward, summing each twin pair and tracking the maximum.
        int i = 0, j = (int)vals.size() - 1;
        while (i < j) {
            maxTwinSum = max(maxTwinSum, vals[i] + vals[j]);
            i++;
            j--;
        }

        return maxTwinSum;
    }
};
