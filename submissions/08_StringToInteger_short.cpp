class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int isNeg = 0;
        int result = 0;
        const int length = str.length();
        
        for(;i<length&&str[i]==' ';i++);
        
        if(str[i]=='+')i++;
        else if(str[i]=='-'){
            isNeg = 1;
            i++;
        }
        for(;i<length;i++){
            if(str[i]<'0'||str[i]>'9'){
                break;
            }
            else if(result>INT_MAX/10||(result == INT_MAX/10&&(str[i]-'0')>INT_MAX%10)){
                return isNeg?INT_MIN:INT_MAX;
            }
            else{
                result = result*10+str[i]-'0';
            }
        }
        return isNeg?-result:result;
    }
};
