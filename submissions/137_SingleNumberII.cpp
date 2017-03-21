/*
Author:FreshMa
Data:17/03/21
Link:https://leetcode.com/problems/single-number-ii/#/description
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/*
这道题想了想肯定是和模3相关，但怎么也想不到如何找出那个数 ，后来看了别人的解答，豁然开朗，位运算！
对每一个数，保存它二进制的每一位，并用一个大小为32的数组存放每一位上1出现的次数，
然后对这个数组进行处理，对i(0<=i<32)位模3，最后按照从低到高的顺序求它对应的二进制值

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(32,0);
        for(int i = 0;i<32;i++){
            for(auto j:nums){
                v[i]+=(j>>i&1);
            }
            v[i]%=3;
        }
        //计算这个数组对应的十进制值，依次左移i位，将结果相加
        int result = 0;
        for(int i = 0;i<32;i++){
            if(v[i]!=0){
                result += v[i]<<i;
            }
        }
        return result;
    }
};
