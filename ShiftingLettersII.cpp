class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int size  = s.size();
        vector<int>diff(size); // diff array 
        for(auto i:shifts){
            if(i[2] == 1){
                diff[i[0]]++;
                if(i[1] + 1 < size){
                    diff[i[1] + 1]--;
                }
            }else {
                diff[i[0]]--;
                if(i[1] +1 < size){ 
                    diff[i[1] +1]++;
                }
            }
        }

        string result(size,' ');
        int numofshift = 0;
        for(int i = 0;i<size ;i++){
           numofshift = (numofshift + diff[i]) % 26;  
            if (numofshift < 0)
                numofshift +=  26;  

            result[i] = 'a' + (s[i] - 'a' + numofshift) % 26;
        }
        return result;

    }
};

/*
// brute force approach 
 
        for (auto i : shifts) {
            for (int j = i[0]; j <= i[1]; j++) {
                if(i[2] == 1){
                    s[j] = (s[j] - 'a' + 1 )%26 + 'a';
                }else {
                    s[j] = (s[j] - 'a' + 25 )% 26   + 'a';
                }
            }
        }
        return s;

*/
