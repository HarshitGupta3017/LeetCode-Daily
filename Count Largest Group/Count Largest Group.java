// Solution for Count Largest Group in JAVA

class Solution {

    private int findDS(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    public int countLargestGroup(int n) {
        Map<Integer, Integer> mp = new HashMap<>();
        int count = 0, maxSize = 0;
        for (int num = 1; num <= n; num++) {
            int digitSum = findDS(num);
            mp.put(digitSum, mp.getOrDefault(digitSum, 0) + 1);
            if (mp.get(digitSum) == maxSize) {
                count++;
            } else if (mp.get(digitSum) > maxSize) {
                maxSize = mp.get(digitSum);
                count = 1;
            }
        }
        return count;
    }
}
