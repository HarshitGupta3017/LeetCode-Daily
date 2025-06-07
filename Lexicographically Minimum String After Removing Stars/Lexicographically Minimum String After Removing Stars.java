// Solution for Lexicographically Minimum String After Removing Stars in JAVA

class Solution {
    public String clearStars(String s) {
        // Custom class to store character and its index
        class CharIndex {
            char ch;
            int idx;
            CharIndex(char ch, int idx) {
                this.ch = ch;
                this.idx = idx;
            }
        }

        // Priority queue with custom comparator
        PriorityQueue<CharIndex> minHeap = new PriorityQueue<>((a, b) -> {
            if (a.ch != b.ch) {
                return Character.compare(a.ch, b.ch); // smaller character first
            } else {
                return Integer.compare(b.idx, a.idx); // smaller index first
            }
        });

        StringBuilder sb = new StringBuilder(s);

        // Step 1: Process the string and replace matched characters with '*'
        for (int i = 0; i < sb.length(); i++) {
            char currentChar = sb.charAt(i);

            if (currentChar != '*') {
                minHeap.offer(new CharIndex(currentChar, i));
            } else {
                if (!minHeap.isEmpty()) {
                    int idxToRemove = minHeap.poll().idx;
                    sb.setCharAt(idxToRemove, '*');  // Mark removed character
                }
            }
        }

        // Step 2: Build the result without '*' characters
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) != '*') {
                result.append(sb.charAt(i));
            }
        }

        return result.toString();
    }
}
