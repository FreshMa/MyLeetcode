class Solution {
public:
    string reverseString(string s) {
        char temp;
        if(s.length() <= 1){
            return s;
        }
        else{
            int i=0;
            int j=s.length()-1;
            for(;i<j;i++,j--){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
            return s;
        }
    }
};
