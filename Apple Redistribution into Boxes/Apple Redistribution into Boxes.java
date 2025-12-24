// Solution for Apple Redistribution into Boxes in JAVA

import java.util.*;

class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {

        // Sort capacities in descending order
        Arrays.sort(capacity);
        int left = 0, right = capacity.length - 1;
        while (left < right) {
            int temp = capacity[left];
            capacity[left] = capacity[right];
            capacity[right] = temp;
            left++;
            right--;
        }

        // Calculate total apples
        int totalApples = 0;
        for (int a : apple) {
            totalApples += a;
        }

        int count = 0;

        // Use largest capacity boxes first
        for (int i = 0; i < capacity.length && totalApples > 0; i++) {
            totalApples -= capacity[i];
            count++;
        }
        return count;
    }
}
