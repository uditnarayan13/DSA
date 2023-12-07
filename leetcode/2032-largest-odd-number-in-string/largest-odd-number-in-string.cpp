class Solution {
public:
    string largestOddNumber(string num) {
        int index=num.size()-1;
        while(index>-1 && (num[index]-'0')%2==0){
            index--;
        }

        return num.substr(0,index+1);
        
    }
};