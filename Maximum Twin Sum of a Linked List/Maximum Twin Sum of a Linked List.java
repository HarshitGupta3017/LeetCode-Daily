// Solution for Maximum Twin Sum of a Linked List in JAVA

class Solution {
    public int pairSum(ListNode head) {

        List<Integer> vals = new ArrayList<>();

        while (head != null) {
            vals.add(head.val);
            head = head.next;
        }

        int maxTwinSum = 0;

        for (int i = 0, j = vals.size() - 1; i < j; i++, j--) {
            maxTwinSum = Math.max(maxTwinSum, vals.get(i) + vals.get(j));
        }

        return maxTwinSum;
    }
}
