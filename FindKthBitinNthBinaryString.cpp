class Solution {
    void solve(string &ans, int n) {
        if (n <= 0){
            return;
        }
        string temp = ans;
        int i = 0, j = temp.size() -1;
        while( i< j){  
            // reverse and invert      
            temp[i] = temp[i] == '1' ? '0' : '1';
            temp[j] = temp[j] == '1' ? '0' : '1';
            swap(temp[i++], temp[j--]); // 
        }
        if (i== j){
           temp[j] = temp[j] == '1' ? '0' : '1';
        }
        ans = ans + "1" + temp;
        solve(ans,n -1); 
    }
    public : 
    char findKthBit(int n, int k) {
      n--;
      string ans = "0";
      solve(ans, n);
      char temp = ans[k-1];
      return temp;
    }
};
