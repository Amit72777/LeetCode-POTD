class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        vector<int> oneindex;
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                oneindex.push_back(i);
            }
        }

        for (int i = 0; i < boxes.size(); i++) {
            int temp = 0;
            for (int j : oneindex) {
                temp += abs(i - j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
