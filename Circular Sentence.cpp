class Solution {
public:
    bool isCircularSentence(string sentence) {
        // simple question -
        // we can just check whenever we encounter space during iterating check prev and next element of it
        // if they are not equal return false - first condition
        // at last check for first and last element too for circular condition - second condition
        int n = sentence.length();
        for (int i = 1; i < n - 1; i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) return false;
        }
        // this is for checking first and last 
        return sentence[0] == sentence[n - 1];
    }
};
