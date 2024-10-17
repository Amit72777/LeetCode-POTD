class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>q;
        string ans = "";
        if (a > 0){
            q.push({a,'a'});
        }
        if (b > 0){
            q.push({b,'b'});
        }
        if (c > 0 ){
            q.push({c,'c'});
        }

        while (!q.empty()) {
            // Get the most frequent character
            pair<int, char> frontNode = q.top();
            q.pop();
            int size = ans.size();

            if (size >= 2 && ans[size - 1] == frontNode.second && ans[size - 2] == frontNode.second) {
                if (q.empty()) break;

                pair<int, char> secondNode = q.top();
                q.pop();

                ans += secondNode.second;
                secondNode.first--;

                if (secondNode.first > 0) q.push(secondNode);

                q.push(frontNode);
            } else {
                ans += frontNode.second;
                frontNode.first--;

                if (frontNode.first > 0) q.push(frontNode);
            }
        }

        return ans;
    }
};
