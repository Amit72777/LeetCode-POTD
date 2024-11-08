class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0;
        int max  = static_cast<int>(pow(2, maximumBit)) - 1 ;  // find maximax value 
        for(auto i :nums){
            x^=i;  // xor of all value in nums 
        }

        for(int i = nums.size() -1 ;i>=0;i--){
            int temp = max ^ x;  // find k value  for maximum xor value 
            x^= nums[i];  //  updatea x by removeing last element of x 
            nums[i] = temp; // store ans 
        }
        reverse(nums.begin(), nums.end()); // reverse ans 
        return nums;  // return ans 
    }
};
