// Solution for Find X-Sum of All K-Long Subarrays II in JAVA

class Solution {

    // Helper class to represent (frequency, value) pairs
    static class Pair implements Comparable<Pair> {
        int freq;
        int val;

        Pair(int freq, int val) {
            this.freq = freq;
            this.val = val;
        }

        // Sort by frequency first, then by value
        @Override
        public int compareTo(Pair other) {
            if (this.freq == other.freq)
                return Integer.compare(this.val, other.val);
            return Integer.compare(this.freq, other.freq);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return freq == p.freq && val == p.val;
        }

        @Override
        public int hashCode() {
            return Objects.hash(freq, val);
        }
    }

    // Helper function to remove a (frequency, value) pair from appropriate set
    private void removeFromSet(Pair pair,
                               TreeSet<Pair> topElements,
                               TreeSet<Pair> remainingElements,
                               long[] currentSumHolder) {

        long currentSum = currentSumHolder[0];

        // Case 1: Element exists in top 'x' frequent elements
        if (topElements.contains(pair)) {
            currentSum -= 1L * pair.freq * pair.val;
            topElements.remove(pair);

            // If topElements has fewer than x elements now, move one from remainingElements
            if (!remainingElements.isEmpty()) {
                Pair largestInRemaining = remainingElements.last(); // highest freq/value
                currentSum += 1L * largestInRemaining.freq * largestInRemaining.val;
                remainingElements.remove(largestInRemaining);
                topElements.add(largestInRemaining);
            }
        } 
        // Case 2: Element exists in remainingElements (not in top x)
        else {
            remainingElements.remove(pair);
        }

        currentSumHolder[0] = currentSum;
    }

    // Helper function to insert a (frequency, value) pair into appropriate set
    private void insertInSet(Pair pair,
                             TreeSet<Pair> topElements,
                             TreeSet<Pair> remainingElements,
                             long[] currentSumHolder, int x) {

        long currentSum = currentSumHolder[0];

        // If topElements has space or the new pair is more frequent/larger
        if (topElements.size() < x || pair.compareTo(topElements.first()) > 0) {
            currentSum += 1L * pair.freq * pair.val;
            topElements.add(pair);

            // If size exceeds x, move the smallest from topElements to remainingElements
            if (topElements.size() > x) {
                Pair smallestInTop = topElements.first();
                currentSum -= 1L * smallestInTop.freq * smallestInTop.val;
                topElements.remove(smallestInTop);
                remainingElements.add(smallestInTop);
            }
        } 
        // Otherwise, insert into remainingElements
        else {
            remainingElements.add(pair);
        }

        currentSumHolder[0] = currentSum;
    }

    // Main function to find x-sum for all subarrays of length k
    public long[] findXSum(int[] nums, int k, int x) {
        List<Long> result = new ArrayList<>();
        Map<Integer, Integer> freqMap = new HashMap<>(); // frequency of each number
        int windowStart = 0;
        long[] currentSumHolder = new long[1]; // holds currentSum by reference

        TreeSet<Pair> topElements = new TreeSet<>();
        TreeSet<Pair> remainingElements = new TreeSet<>();

        for (int windowEnd = 0; windowEnd < nums.length; windowEnd++) {
            int currentNum = nums[windowEnd];

            // If number already exists, remove old frequency pair
            if (freqMap.getOrDefault(currentNum, 0) > 0) {
                removeFromSet(new Pair(freqMap.get(currentNum), currentNum),
                              topElements, remainingElements, currentSumHolder);
            }

            // Increment its frequency and re-insert with updated count
            freqMap.put(currentNum, freqMap.getOrDefault(currentNum, 0) + 1);
            insertInSet(new Pair(freqMap.get(currentNum), currentNum),
                        topElements, remainingElements, currentSumHolder, x);

            // Once window reaches size k, record x-sum and slide window
            if (windowEnd - windowStart + 1 == k) {
                result.add(currentSumHolder[0]);

                int outgoingNum = nums[windowStart];
                removeFromSet(new Pair(freqMap.get(outgoingNum), outgoingNum),
                              topElements, remainingElements, currentSumHolder);
                freqMap.put(outgoingNum, freqMap.get(outgoingNum) - 1);

                // If outgoingNum still exists, re-insert with updated frequency
                if (freqMap.get(outgoingNum) == 0) {
                    freqMap.remove(outgoingNum);
                } else {
                    insertInSet(new Pair(freqMap.get(outgoingNum), outgoingNum),
                                topElements, remainingElements, currentSumHolder, x);
                }

                windowStart++;
            }
        }

        // Convert List<Long> to long[]
        long[] ans = new long[result.size()];
        for (int i = 0; i < result.size(); i++) ans[i] = result.get(i);
        return ans;
    }
}
