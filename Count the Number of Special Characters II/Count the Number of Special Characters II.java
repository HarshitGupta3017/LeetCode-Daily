// Solution for Count the Number of Special Characters II in JAVA

class Solution {
    public int numberOfSpecialChars(String word) {

        int[] lastLowercaseIndex = new int[26];
        int[] firstUppercaseIndex = new int[26];

        Arrays.fill(lastLowercaseIndex, -1);
        Arrays.fill(firstUppercaseIndex, -1);

        for (int index = 0; index < word.length(); index++) {

            char currentCharacter = word.charAt(index);

            if (Character.isLowerCase(currentCharacter)) {

                lastLowercaseIndex[currentCharacter - 'a'] = index;
            } 
            else {

                if (firstUppercaseIndex[currentCharacter - 'A'] == -1) {

                    firstUppercaseIndex[currentCharacter - 'A'] = index;
                }
            }
        }

        int specialCharacterCount = 0;

        for (int alphabetIndex = 0; alphabetIndex < 26; alphabetIndex++) {

            if (lastLowercaseIndex[alphabetIndex] != -1 &&
                firstUppercaseIndex[alphabetIndex] != -1 &&
                lastLowercaseIndex[alphabetIndex] < firstUppercaseIndex[alphabetIndex]) {

                specialCharacterCount++;
            }
        }

        return specialCharacterCount;
    }
}
