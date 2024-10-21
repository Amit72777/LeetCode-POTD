class Solution {
    // Helper function to find max unique splits
    int backtrack(string &s, int start, unordered_set<string> &seen) {
        if (start == s.size()) return 0; // Base case

        int maxcnt = 0;
        // Try every substring from 'start'
        for (int end = start + 1; end <= s.size(); ++end) {
            string sub = s.substr(start, end - start);

            // If substring is unique, proceed
            if (seen.find(sub) == seen.end()) {
                seen.insert(sub);  // Mark substring as used
                maxcnt = max(maxcnt, 1 + backtrack(s, end, seen));  // Recur for the next part
                seen.erase(sub);  // Backtrack
            }
        }
        return maxcnt;  // Return max count of unique splits
    }

public:
    // Main function to start the process
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }
};
