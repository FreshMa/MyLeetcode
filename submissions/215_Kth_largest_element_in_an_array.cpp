/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/*
使用快排的思路：
1.找一个元素x，使用快排中的划分算法确定它在数组中的位置pos，划分结束后，比x大的都在左边，
比x小的都在右边
2.如果pos==k-1，说明x就是要找的元素
3.如果pos>k-1，说明第k大的数就是左边部分第k大的数，递归寻找
4.如果pos<k-1，那么第k大的数在右边，在右半部分中找数组中第k大的数
*/

class Solution{
public:
  int partition(vector<int> &nums, int s, int e){
    int flag = nums[s];
    while(s<e){
      while(s<e && nums[e]<=flag) e--;
      nums[s] = nums[e];
      while(s<e && nums[s]>=flag) s++;
      nums[e] = nums[s];
    }
    nums[s] = flag;
    return s;
  }

  int helper(vector<int>& nums, int s, int e, int k){
    if(s==e) return nums[s];
    int pos = partition(nums, s, e);
    if(pos==k-1) return nums[pos];
    if(pos>k-1) return helper(nums, s, pos-1, k);
    if(pos<k-1) return helper(nums, pos+1, e, k);
  }

  int findKthLargest(vector<int>& nums, int k){
    return helper(nums, 0, nums.size()-1, k);
  }
};
