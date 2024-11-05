class Solution {
public:
    int minChanges(string s) {
      int cnt = 0;
      int i = 0;
      while(i< s.size()){
        // make two pair 
        if(s[i] != s[i+1]){ // Check two value are equal or not 
            cnt++; // if not equal then you need to change to make string beautiful 
        }
        i+=2;
      }  
      return cnt;
    }
};
