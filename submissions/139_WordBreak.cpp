/*
Author:FreshMa
Date:17/04/01
Link:https://leetcode.com/problems/word-break/#/description
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
/*
一开始设想首先统计wordDict中的每一项是否在字符串s中出现过，并统计出现次数；
用出现过的每一项的长度乘以出现次数，加起来是否与字符串s长度相等。这个想法过了23/34。
然后看了看Tag，动态规划，于是就想状态转移方程，最后还是算参考了一部分别人的思想：
1.用vector  tv保存出现在字符串s中的wordDict中的项
2.排序该Vector，即tv
3.定义状态dp[i]，它代表tv中的项能否构造出s的前i段，即s.substr(0,i)
4.定义转移方程：dp[i] = dp[i-strlen]&&(s.substr(i-strlen,strlen)==str),strlen = str.length()
5.只要在tv中找到任何一个使dp[i]为真的项，就将它置为真并跳出该循环
状态是看了别人的解法之后确认的，其他的都是自己想的（强行贴金
*/
/*
AC 34/34 3ms beats 81%,第一梯队
*/

class Solution {
public:
   //辅助函数，用来按长度排序
    bool static comp(string &a,string &b){
        return a.length()<b.length();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        //明明是有空的，描述中说没有
        if(s.length()==0||wordDict.size()==0)
            return false;

        int slen = s.length();
        vector<string> tv;
        //保存出现在s中的wordDict项
        for(auto i:wordDict){
            if(s.find(i)!=string::npos){
                tv.push_back(i);
            }
        }
        //如果为空，直接返回false
        if(tv.size()==0)
            return false;

        //按长度排序
        sort(tv.begin(),tv.end(),comp);
        //dp[i]代表wordDict中的项能否构成s的前i个字符
        vector<bool> dp(slen+1,false);
        dp[0] = true;
        //从tv[0]，即最短的开始循环
        for(int i = tv[0].length();i<=slen;i++){
            for(auto str:tv){
                int l = str.length();
                //字符串的长度可能会大于i，这时直接略过
                if(i>=l){
                    //s.substr(0,i) = s.substr(0,i-l)+s.substr(i-1,l)
                    //所以我们需要判断这两部分是否都为真
                    dp[i]=dp[i-l]&&(s.substr(i-l,l)==str);
                    //一旦为真，保存并退出
                    if(dp[i])
                        break;
                }
            }
        }
        return dp[slen];
    }
};
