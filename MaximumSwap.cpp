class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int size = str.size();
        vector<int>maxindex(size);
        maxindex[size - 1] = size - 1;
        for(int i = size-2;i>=0;i--){  // store a maximum value index in assending order 
            maxindex[i] = str[i] > str[maxindex[i+1]] ? i : maxindex[i+1];
        }

        for(int i = 0; i< size;i++){
            if (str[i] < str[maxindex[i]]){
                swap(str[i] , str[maxindex[i]]);  // if swap the return ans;
                return stoi(str);
            }
        }
        return num; // no need to swaps

    }
};
