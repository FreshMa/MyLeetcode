/*
Author:FreshMa
Date:17/04/03
Link:https://leetcode.com/problems/next-permutation/#/description
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
/*
非递归的方法如下：
vector<int> nums;
1.find j st. j = max{i|nums[i]<nums[i+1]}
2.find k st. k = max(i|nums[i]>nums[j])
3.swap(nums[j],nums[k])
4.reverse(nums.begin()+j+1,nums.end());
*/
/*
AC 265/265 12ms beats 64%
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j =-1,k = -1;
        int len = nums.size();
        if(len<2){
            return;
        }
        for(int i = 0;i<len-1;i++){
            if(nums[i]<nums[i+1]){
                j = j>i?j:i;
            }
        }
        //如果找不到下一个排列，就返回递增的排列
        if(j==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        for(int i = j;i<len;i++){
            if(nums[i]>nums[j])
                k = i>k?i:k;
        }
        
        int t = nums[j];
        nums[j] = nums[k];
        nums[k] = t;

        for(int s = j+1,e = len-1;s<e;s++,e--){
            int tt = nums[s];
            nums[s] = nums[e];
            nums[e] = tt;
        }

    }
};
