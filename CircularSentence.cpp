class Solution {
public:
    bool isCircularSentence(string sentence) {
        int i = 0,size = sentence.size();
        while(i<size){
            if(i+1 < size && sentence[i+1] == ' '){
                char ch  = sentence[i];
                i+=2;
                if(i<size && sentence[i] != ch){
                    return false;
                }
            }
            else {
                i++;
            }
        }

        if(sentence[i-1] !=  sentence[0]){
            return false;
        }
        return true;
    }
};
