// Solution for Final Value of Variable After Performing Operations in JAVA

class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;
        for (String o: operations) x = (o.charAt(1) == '-') ? x - 1 : x + 1;
        return x;
    }
}
