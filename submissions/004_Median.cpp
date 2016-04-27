
class Solution {
public:
//返回一个合并后数组的中位数，两个原数组分别有m和n个元素。
    double getMedian(int m,int n,vector<int>& num){
        int pos1 = (m+n)/2;
        int pos2 = pos1 - 1;
        double result = 0;
        if((m+n)%2 == 0){
            result = (double) (num[pos1]+num[pos2])/2;
        }
        else{
            result = num[pos1];
        }
        return result;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int m = nums1.size();
        int n = nums2.size();
        double result;
        //如果两个数组至少有一个元素，那么就进行合并工作
        //合并两个已排序的数组，复杂度为O(m+n)
        else if((m>=0)&&(n>=0)){
            //p1和p2指向未比较的第一个元素
            int p1 = 0;
            int p2 = 0;
            while((p1<m)&&(p2<n)){
               if(nums1[p1]<nums2[p2]){
                   merge.push_back(nums1[p1]);
                   p1++;
               }
               else{
                   merge.push_back(nums2[p2]);
                   p2++;
               }
            }
            //如果某个数组已经被遍历，那么将另一个数组的元素依次添加到合并后数组中
            if(p1 == m){
                while(p2 < n){
                    merge.push_back(nums2[p2++]);
                }
            }
            else if(p2 == n){
                while(p1 < m){
                    merge.push_back(nums1[p1++]);
                }
            }
            result = getMedian(m,n,merge);
        }
       
        return result;
    }
};
