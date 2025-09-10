// Solution for Minimum Number of People to Teach in CPP

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& userLanguages, vector<vector<int>>& friendships) {
        set<int> usersWhoCannotCommunicate; // Users involved in friendships where they cannot talk

        // Step 1: Identify users who cannot communicate with their friends
        for (auto& friendship : friendships) {
            int userA = friendship[0] - 1; // convert to 0-based index
            int userB = friendship[1] - 1;

            set<int> languagesOfA(userLanguages[userA].begin(), userLanguages[userA].end());

            bool canCommunicate = false;
            for (int lang : userLanguages[userB]) {
                if (languagesOfA.count(lang)) { // Check if they share at least one language
                    canCommunicate = true;
                    break;
                }
            }

            if (!canCommunicate) {
                usersWhoCannotCommunicate.insert(userA);
                usersWhoCannotCommunicate.insert(userB);
            }
        }

        // Step 2: Count frequency of languages known by users who cannot communicate
        vector<int> languageFrequency(n + 1, 0); // languageFrequency[i] = # of sad users knowing language i
        int maxLanguageFrequency = 0;

        for (int user : usersWhoCannotCommunicate) {
            for (int lang : userLanguages[user]) {
                languageFrequency[lang]++;
                maxLanguageFrequency = max(maxLanguageFrequency, languageFrequency[lang]);
            }
        }

        // Step 3: Minimum number of users to teach = total sad users - most frequent language among them
        return usersWhoCannotCommunicate.size() - maxLanguageFrequency;
    }
};
