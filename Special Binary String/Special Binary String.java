// Solution for Special Binary String in JAVA

class Solution {
    public String makeLargestSpecial(String s) {
        List<String> blocks = new ArrayList<>();
        int balance = 0, start = 0;

        for (int i = 0; i < s.length(); i++) {
            balance += s.charAt(i) == '1' ? 1 : -1;

            if (balance == 0) {
                String inner = s.substring(start + 1, i);
                blocks.add("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        Collections.sort(blocks, Collections.reverseOrder());
        return String.join("", blocks);
    }
}
