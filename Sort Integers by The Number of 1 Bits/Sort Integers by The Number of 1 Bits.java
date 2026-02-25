// Solution for Sort Integers by The Number of 1 Bits in JAVA

class Solution {
    public int[] sortByBits(int[] arr) {
        Integer[] boxed = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        
        Arrays.sort(boxed, (a, b) -> {
            int countA = Integer.bitCount(a);
            int countB = Integer.bitCount(b);
            
            if (countA == countB) {
                return a - b;
            }
            return countA - countB;
        });
        
        for (int i = 0; i < arr.length; i++) {
            arr[i] = boxed[i];
        }
        
        return arr;
    }
}
