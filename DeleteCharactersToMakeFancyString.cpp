class Solution {
public:
    string makeFancyString(string s) {
        string ansStr = ""; // store ans 
        int i = 0, size = s.size();// first pointer index 
        while (i < size) {
            ansStr += s[i]; // add character ans 
            int j = i + 1; // next pointer in next position 
            // if next char is same than add ans for make it fancy 
            if (j < size && s[i] == s[j]) {
                ansStr += s[i];
            }
            // next pointer in increrment continiously becacue 2 character are same as most in sequence 
            while (j < size && s[i] == s[j]) {
                j++;
            }
            i = j; // assign next variable 
        }
        return ansStr; // return ans 
    }
};
