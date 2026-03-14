// Solution for The k-th Lexicographical String of All Happy Strings of Length n in CPP

class Solution {
public:

    /*
        Backtracking function to generate all possible happy strings.

        Parameters:
        n              -> required length of the happy string
        k              -> we want the k-th happy string
        currentString  -> string currently being built
        kthResult      -> stores the k-th happy string once found
        generatedCount -> counts how many valid happy strings we have generated so far
    */
    void generateHappyStrings(
        int n,
        int k,
        string& currentString,
        string& kthResult,
        int& generatedCount
    ) {

        /*
            Base Case:
            If the current string has reached length n,
            we have formed a valid happy string.
        */
        if (currentString.size() == n) {

            // Increase the number of happy strings generated
            generatedCount++;

            /*
                If this is the k-th generated happy string,
                store it as the result.
            */
            if (generatedCount == k)
                kthResult = currentString;

            return;
        }

        /*
            Try appending characters 'a', 'b', and 'c'
            in lexicographical order.
            This ensures generated strings are naturally sorted.
        */
        for (char candidateChar = 'a'; candidateChar <= 'c'; candidateChar++) {

            /*
                Happy string rule:
                Adjacent characters must NOT be equal.

                So if the last character of the current string
                is the same as the candidate character,
                we skip it.
            */
            if (!currentString.empty() && currentString.back() == candidateChar)
                continue;

            /*
                Choose the character
                (add it to the current string).
            */
            currentString.push_back(candidateChar);

            /*
                Recurse to build the rest of the string.
            */
            generateHappyStrings(n, k, currentString, kthResult, generatedCount);

            /*
                Backtrack:
                Remove the last character to try another possibility.
            */
            currentString.pop_back();
        }
    }

    string getHappyString(int n, int k) {

        /*
            Tracks how many happy strings we have generated.
        */
        int generatedCount = 0;

        /*
            Will store the final k-th happy string.
        */
        string kthResult = "";

        /*
            Temporary string used during backtracking.
        */
        string currentString = "";

        /*
            Start generating happy strings.
        */
        generateHappyStrings(n, k, currentString, kthResult, generatedCount);

        return kthResult;
    }
};
