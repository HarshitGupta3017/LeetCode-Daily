class Solution {
public:
    bool rotateString(string s, string goal) {
        // easy question
        // so first thing we notice that if we rotate string s
        // in example as shown s = "abcde" if we rotate this one by one it will become
        // "abcdeabcde" i.e. s+s and the rotated string that is goal should be present in this now
        // as after rotating each character of string s it becomes 2*s so goal is one of the string 
        // among this rotated one so it should be present in that if not then return false
        // also the length of both strings should be same otherwise can't be rotated
        // (s+s).find(goal) != string::npos - its basically checking if goal is present in s+s
        // if yes then it won't be equal to npos otherwise it will return false
        return (s.size() == goal.size() && (s+s).find(goal) != string::npos);
    }
};
