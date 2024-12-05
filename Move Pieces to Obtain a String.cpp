class Solution {
public:
    bool canChange(string start, string target) {
        // so a 2-pointer based simple ques, how??
        // lets check
        int n = start.size(), i = 0, j = 0;
        // loop until any one pointer doesnot reached the end
        while (i < n || j < n) {
            // skip blank spaces first to check the characters 
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;
            // now check if both pointers reached end then the strings are equal
            if (i == n && j == n) return true;
            // otherwise
            // if any one pointer doesn't reached the end 
            // and then check the characters
            // if they are not equal return false
            // also check the condition that if char is L it will move left so for eg
            // start = "__L", target = "_L_"
            // here if index of char "L" in start is greater or equal than that of target it can be made 
            // equal otherwise not right?? check once
            // if start = "_L__", target = "__L", they cant be made equal as start 'L' cant go to right
            // same for char 'R' should be less than or equal to that of target otherwise cant go right
            if ((i == n || j == n) || (start[i] != target[j]) || (start[i] == 'L' && i < j) || 
            (start[i] == 'R' && i > j)) return false;
            i++, j++;
        }
        return true;
    }
};
