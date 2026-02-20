// Solution for Special Binary String in CPP

class Solution {
public:

    /*
        Goal:
        Rearrange consecutive special substrings
        to make the string lexicographically largest.

        Strategy:
        1. Break the string into top-level special blocks.
        2. Recursively maximize each block's inner part.
        3. Sort the blocks in descending order.
        4. Join them together.
    */

    string makeLargestSpecial(string s) {

        /*
            This vector will store all the top-level
            special substrings found in 's'.
        */
        vector<string> blocks;

        /*
            balance:
            +1 for '1'
            -1 for '0'

            When balance becomes 0,
            we found a complete special substring.
        */
        int balance = 0;

        /*
            start marks where the current
            special block begins.
        */
        int start = 0;

        /*
            Scan through the string.
        */
        for (int i = 0; i < s.size(); i++) {

            // Increase balance for '1', decrease for '0'
            if (s[i] == '1')
                balance++;
            else
                balance--;

            /*
                If balance == 0,
                number of 1's equals number of 0's
                → we found one complete special substring.
            */
            if (balance == 0) {

                /*
                    Structure of a special block:

                    s[start] is always '1'
                    s[i]     is always '0'

                    Inside them is another special string.

                    Example:
                    110100

                    If start = 0, i = 5
                    inner = s[1..4]
                */

                string inner = s.substr(start + 1, i - start - 1);

                /*
                    Recursively maximize the inner part.
                    Why?

                    Because inner itself may contain
                    smaller special blocks that can
                    be rearranged to become larger.
                */
                string maximizedInner = makeLargestSpecial(inner);

                /*
                    Rebuild this special block:

                    1 + (maximized inner) + 0
                */
                string fullBlock = "1" + maximizedInner + "0";

                blocks.push_back(fullBlock);

                /*
                    Move start to next position
                    after current block.
                */
                start = i + 1;
            }
        }

        /*
            IMPORTANT PART:

            We are allowed to swap consecutive
            special substrings.

            That means we can reorder the top-level blocks.

            To get lexicographically largest result,
            we sort them in descending order.
        */
        sort(blocks.begin(), blocks.end(), greater<string>());

        /*
            Join them together.
        */
        string result = "";

        for (string &block : blocks) {
            result += block;
        }

        return result;
    }
};
