/*
https://leetcode.com/problems/search-for-a-range/

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int h = len-1;
        int start_pos = -1;
        int end_pos = -1;
        vector<int> r = {-1,-1};
        //如果该数不在数组范围内，直接返回[-1,-1]
        if(nums[l]>target||nums[h]<target)
        {
            return r;
        }
        //target在数组范围内，采用二分法来定位该数字
        while(l<=h)
        {
            int m = (l+h)/2;
            //如果找到了该数字
            if(nums[m] == target){
                int t = m;
                //找出其起始位置
                for(;t>=0 && nums[t]==target;t--);
                start_pos = t+1;
                //重置t
                t = m;
                //找出其结束的位置
                for(;t<len && nums[t]==target;t++);
                end_pos = t-1;
                //重新赋值
                r[0] = start_pos;
                r[1] = end_pos;
                //退出循环
                break;
            }
            else if(nums[m]<target)
            {
            //当中间数比target小的时候，需要把左指针向右移一位，注意不能直接l=m，会造成死循环
                l = m+1;
            }
            else
            {
            //同理当中间数比target大的时候，需要把右指针向左移一位，同样也不能直接h=m，以免造成死循环
                h = m-1;
            }
        }
        return r;
    }
};
