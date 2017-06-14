/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
全排列相关的问题基本都可以用以下两种方法解决，尤其是迭代版可以解决诸如字典序的问题。
*/
/*
1.递归版：
依次把除第一个元素之外的元素放到第一位，然后对其余元素进行全排列。
退出条件是待排序的元素只剩最后一个，一个元素的全排列只有一种。此时就可以推出了
*/
class Solution {
public:
    void helper(vector<vector<int>> &res,vector<int> &nums,int k,int N){
        if(k==N){
            res.push_back(nums);
            return;
        }
        //依次调换位置，记得换回来，好换下一个
        for(int i = k;i<N;i++){
            swap(nums[i],nums[k]);
            helper(res,nums,k+1,N);
            swap(nums[i],nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(res,nums,0,nums.size());
        return res;
    }
};

/*
2.迭代版：
迭代版的思想是从第一个排列开始生成下一个排列，即最终结果是符合字典序的。
而生成下一个排列的算法如下：
从头开始找到最后一个符合nums[i]<nums[i+1]的i，这意味着序列被分为两个部分，后一部分是按字典序递减的。
在后一部分中找到最后一个大于nums[i]的数，假设该数是j。
交换nums[i]到nums[j]的位置，然后翻转从nums[i+1]到[j]范围内的元素。

一直到找不到元素满足nums[i]<nums[i+1]为止。
代码如下：
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);

        int len = nums.size();
        //int flag = 1;
        while(1){
            int j = -1,k = -1;
            for(int i = 0;i<len-1;i++){
                if(nums[i]<nums[i+1])
                    j=j>i?j:i;
            }
            //没找到递增序列，即退出
            if(j==-1)
                break;
            for(int i = j;i<len;i++){
                if(nums[i]>nums[j])
                    k = i>k?i:k;
            }
            //交换元素
            int t = nums[j];
            nums[j] = nums[k];
            nums[k] = t;
            //重排序列
            for(int s = j+1,e = len-1;s<e;s++,e--){
                int tt = nums[s];
                nums[s] = nums[e];
                nums[e] = tt;
            }
            res.push_back(nums);
        }
        return res;
    }
};
