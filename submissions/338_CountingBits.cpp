/*
Counting Bits

https://leetcode.com/problems/counting-bits/?tab=Description

Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

-----------------------------------------------
首先想到计算每一个i的1bit位数，最后再加起来，但是这很明显不符合题目的用意；
进一步观察每一位数字中1的位数的规律，发现如果i是2的整数次幂的话，i就只有一个1 bit，
而且i+1 的1bit位就是i 的bit位加上1的bit位，一直到2i-1，是i的bit位加上i-1的bit位，2i又是一个 1bit位，
这下规律就很明显了，可以用一个num+1大小的数组保存每一个i(0<=i<=num)的1 bit位数，以便后面直接使用，从而大大简化运算
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> rv(num+1);
        if(num == 0)
        {
            return rv;
        }
        else
        {
            for(int i = 1;i<=num;i++)
            {
                int count = 0;
                int t = i;
                t = t>>1;
                while(t!=0)
                {
                    t = t>>1;
                    count++;
                }
                if((i>>count) == 0)
                    rv[i] = 1;
                else
                {
                    int indent = 1<<count;
                    rv[i] = 1+rv[i-indent];
                }
            }
            return rv;
        }
    }
};
