/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/

/*
排序问题，将一个只含有0，1，2的无序数组按012排列.
题目中不允许使用stl的排序，所以我们考虑用O(n)的时间复杂度来解决：
两个指针，一个记录扫描到目前为止最后一个0之后的位置p1,，另一个记录最后一个2之前的位置p2,
进行迭代，若当前扫描的位置是i，如果nums[i]==0,swap(nums[p1++],nums[i]);
如果nums[i]==2，swap(nums[p2--],nums[i]);
当i和p2相遇时，证明已经排好序了。即所有的0都在最前面，所有的2都在最后面，中间的自然是1了
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0;
        int p2 = nums.size()-1;
        //找到第一个不为0的位置
        while(nums[p1]==0) p1++;
        //找到最后一个不为2的位置
        while(nums[p2]==2) p2--;
        for(int i = p1;i<=p2;){
            if(nums[i]==0){
                swap(nums[i++],nums[p1++]);
            }
            else if(nums[i]==2){
              //此时有可能把0换到了i处，所以i不能增加，需要对其进行判断
                swap(nums[i],nums[p2--]);
            }
            else
                i++;
        }
    }
};
