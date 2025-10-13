// Solution for Find Resultant Array After Removing Anagrams in JAVA

class Solution {

    private boolean checkAnagram(String s1, String s2) {
        int[] arr = new int[26];
        for (char ch: s1.toCharArray()) {
            arr[ch - 'a']++;
        }
        for (char ch: s2.toCharArray()) {
            arr[ch - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }

    public List<String> removeAnagrams(String[] words) {
        List<String> result = new ArrayList<>();
        result.add(words[0]);
        for (int i = 1; i < words.length; i++) {
            if (!checkAnagram(result.get(result.size() - 1), words[i])) {
                result.add(words[i]);
            }
        }
        return result;
    }
}
