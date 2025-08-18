// Solution for 24 Game in JAVA

class Solution {
    double epsilon = 1e-6;

    private boolean canMake24(List<Double> numbers) {
        if (numbers.size() == 1) {
            return Math.abs(numbers.get(0) - 24.0) <= epsilon;
        }
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = 0; j < numbers.size(); j++) {
                if (i == j) continue;
                List<Double> remaining = new ArrayList<>();
                for (int k = 0; k < numbers.size(); k++) {
                    if (k != i && k != j) remaining.add(numbers.get(k));
                }
                double num1 = numbers.get(i);
                double num2 = numbers.get(j);
                List<Double> results = new ArrayList<>();
                results.add(num1 + num2);
                results.add(num1 - num2);
                results.add(num2 - num1);
                results.add(num1 * num2);
                if (Math.abs(num2) > 0) results.add(num1 / num2);
                if (Math.abs(num1) > 0) results.add(num2 / num1);
                for (double val : results) {
                    remaining.add(val);
                    if (canMake24(remaining)) return true;
                    remaining.remove(remaining.size() - 1);
                }
            }
        }
        return false;
    }

    public boolean judgePoint24(int[] cards) {
        List<Double> nums = new ArrayList<>();
        for (int card : cards) nums.add((double) card);
        return canMake24(nums);
    }
}
