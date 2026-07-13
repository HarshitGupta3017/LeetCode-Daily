// Solution for Sequential Digits in JAVA

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        // Seed the queue with single-digit numbers 1–8.
        // 9 is excluded because it cannot be extended.
        Queue<Integer> queue = new LinkedList<>();
        for (int digit = 1; digit <= 8; digit++) {
            queue.offer(digit);
        }

        List<Integer> result = new ArrayList<>();

        while (!queue.isEmpty()) {
            int num = queue.poll();

            // Collect numbers within the target range.
            if (num >= low && num <= high) {
                result.add(num);
            }

            // No need to expand numbers already larger than high.
            if (num > high) {
                continue;
            }

            // Append the next sequential digit.
            int lastDigit = num % 10;
            if (lastDigit < 9) {
                queue.offer(num * 10 + (lastDigit + 1));
            }
        }

        // BFS naturally generates numbers in sorted order.
        return result;
    }
}
