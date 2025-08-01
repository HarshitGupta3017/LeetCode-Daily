// Solution for Pascal's Triangle in JAVA

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>(Collections.nCopies(i + 1, 1));
            for (int j = 1; j < i; j++) {
                row.set(j, result.get(i - 1).get(j) + result.get(i - 1).get(j - 1));
            }
            result.add(row);
        }
        return result;
    }
}
