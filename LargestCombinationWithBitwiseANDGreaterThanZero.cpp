
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt = 0;
        for (int i = 0; i < 24; i++) {
            int temp = 0;
            for (auto num : candidates) {
                if ( num& (1 << i)) {
                    temp++;
                }
            }
            cnt = max(temp, cnt);
        }
        return cnt;
    }
};
