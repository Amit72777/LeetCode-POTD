class Solution {
    bool evaluate(string& expression, int &index){
        char ch = expression[index];
        index++;
        if (ch == 't'){ // base case 
            return true;
        }
        else if (ch == 'f'){
            return false;
        }

        if (ch == '!'){ // calculat NOT operator 
            index++;
            bool flag = !evaluate(expression, index);
            index++;
            return flag;
        }

        vector<bool>value;
        index++;
        while(expression[index] != ')'){ // store value for calculate AND and OR oerator 
            if (expression[index] == ','){
                index++;
            }else {
                value.push_back(evaluate( expression,index));
            }
        }
        index++;

        // handle AND Opeeration 
        if (ch == '&'){
            for(bool cv: value){
                if (!cv) return false;
            }
            return true;
        }

        // handle OR 
        if (ch == '|'){
            for (bool cv:value){
                if (cv) return true;
            }
            return false;
        }

        return false;

    }
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return evaluate(expression , index);
    }
};
