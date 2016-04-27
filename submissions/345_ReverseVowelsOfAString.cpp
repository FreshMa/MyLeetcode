class Solution {
//find_first_of:该函数从字符串开头开始匹配模式字符串中的任意字符，并返回首次匹配的位置；加一个位置参数，表示从该位置开始匹配
//find_last_of:该函数从字符串尾部开始匹配模式字符串中的任意字符，并返回第一个匹配的位置；加一个位置参数，表示从该位置开始匹配
public:
    string reverseVowels(string s) {
        string vowel = "aoeiuAOEIU";
        if(s.length() == 0){
            return s;
        }
        else{
            int i = s.find_first_of(vowel);
            int j = s.find_last_of(vowel);
            while(i!=s.npos&&j!=s.npos&&i<j){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                
                i = s.find_first_of(vowel,i+1);
                j = s.find_last_of(vowel,j-1);
            }
        }
        return s;
    }
};
