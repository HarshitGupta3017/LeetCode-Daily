// Solution for Jump Game III in JAVA

class Solution {
    public boolean canReach(int[] arr, int start) {

        // Invalid index or already visited
        if (start < 0 || start >= arr.length || arr[start] < 0) {
            return false;
        }

        // Reached value 0
        if (arr[start] == 0) {
            return true;
        }

        int jump = arr[start];

        // Mark as visited
        arr[start] = -1;

        // Try forward and backward jumps
        return canReach(arr, start + jump) ||
               canReach(arr, start - jump);
    }
}
