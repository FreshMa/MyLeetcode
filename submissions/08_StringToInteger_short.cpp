class Solution {
    /*
    通过对测试例子的观察，我们发现只有合法的字符串才能被转为整数并返回该整数，不合法的返回0。而合法的定义如下：
    1.字符串的有效字符包括‘+’，‘-’，‘ ’（空格）以及数字；
    2.只有以有效字符开始的字符串才有可能是合法的字符串；
    3.以有效字符开始，中间出现无效字符，则将无效字符之前的字符串转为整数。
    整体思路如下：
    1.排除有效字符之前的尽可能多的空格，标记这个位置；
    2.判断是正数还是负数，并做标记；
    3.从标记的位置开始遍历，如果发现无效字符，则退出循环；
    4.如果该字符串代表的数字超过了int的边界，则根据正负标记返回INT_MAX或INT_MIN；
    5.计算结果并保存，计算方法是给上一次的结果乘以10再加上此次循环的字符代表的数字；
    6.根据正负标记返回整数。
    */
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
