// Solution for Process String with Special Operations I in CPP

class Solution {
public:
   string processStr(string s) {
       string result;

       for (char ch : s) {
           if (ch == '*') {
               // Remove the most recently added character.
               // The guard prevents undefined behaviour on an already-empty result.
               if (!result.empty())
                   result.pop_back();
           }
           else if (ch == '#') {
               // Append a copy of the current result to itself.
               // result += result is safe in C++11 and later — the standard
               // guarantees the right-hand side is evaluated before the append.
               result += result;
           }
           else if (ch == '%') {
               // Reverse the entire result in place.
               reverse(result.begin(), result.end());
           }
           else {
               // Any lowercase letter is appended directly.
               result += ch;
           }
       }

       return result;
   }
};
