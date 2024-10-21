class Solution {

    int backtrack(string  &s, int start ,unordered_set<string>&seen ){
        if (start == s.size()){
            return 0; // base case 
        }
        int maxcnt = 0;
        for (int end = start +1; end <= s.size();++end){
            string sub = s.substr(start,end-start); 
            if (seen.find(sub) == seen.end()){
                seen.insert(sub);
                maxcnt = max(maxcnt, 1+ backtrack(s,end,seen));
                seen.erase(sub);
            }
        }
        return maxcnt; // retunn max 
    }
public:
    int maxUniqueSplit(string s) {
    unordered_set<string>seen;
    return backtrack(s, 0, seen); 
    }
};
