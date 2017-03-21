/*
Author:FreshMa
Date:17/03/21
Link:https://leetcode.com/problems/reverse-words-in-a-string/#/description
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
*/

/*
字符串翻转一般考虑先部分翻转，再整体翻转，所以就需要一个辅助函数，来进行指定位置元素
的翻转工作，这里我们定义了helper()函数来进行这项工作，该函数所需空间为O(1)。

然后需要考虑字符串中的空格：
1.头和尾的空格需要去掉，并返回一个去掉头尾空格的字符串
2.字符串中间用来分隔子串的空格只需要一个就行了，所以采用string的erase函数来抹除多余的空格

最后进行先局部，后整体的翻转工作
*/

class Solution {
public:
    //辅助函数，进行串s内st到en位置的翻转工作
    void helper(string &s, int st, int en) {
	    for (int i = st, j = en; i < j; i++, j--) {
		    char t = s[i];
		    s[i] = s[j];
		    s[j] = t;
	    }
    }

    void reverseWords(string &s) {
        int pos = 0;
        int len = s.length();
        //去掉开头的空格
        while(s[pos]==' ') pos++;
        s = s.substr(pos,len-pos);
        //然后去掉尾部的空格
        if(s.length()!=0){
            int suf = s.length()-1;
            while(s[suf]==' ') suf--;
            s = s.substr(0,suf+1);
        }
        //此时，pos应该被重新指向新串的开头
        pos = 0;
        int found = s.find(" ");
        //循环读取字符串，
        //如果找到空格，对pos和found之间的串进行翻转
        //如果没有找到，意味着到达串的结尾，那么翻转pos到串结尾部分的字符串
        while(true){
            if(found!=string::npos){
                helper(s,pos,found-1);
                int loc = found+1;
                int count = 0;
                while(s[loc++]==' ') count++;
                s = s.erase(found+1,count);
                pos = ++found;
                found = s.find(" ",pos);
            }
            else{
                helper(s,pos,s.length()-1);
                break;
            }

        }
        //最后进行整体翻转
        helper(s,0,s.length()-1);
    }
};
