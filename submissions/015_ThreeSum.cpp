/*
想了半天，还是靠百度找到的思路= =
问题是找到三个数，使其和为0，那么可以转化为：两个数之和是另一个数的绝对值。
也就是找到两个数，这两个数的和是一个定值，这个定值是数组中的任意数。
如果是递增数组的话，设置两个指针，一个指向开头，一个指向结尾，计算这两个数的和，如果小于定值，那么头指针右移，从而使和更大；如果大于定值，则尾指针左移。
外部循环给定值赋值。
步骤如下：
1.先将数组升序排列，这一步可以使用STL中的sort函数，也可以自己写一个排序函数
2.外层循环，定值的取值为数组中的元素；如果数组中有多个元素相同，当且仅当定值取过第一个之后，可以跳过剩余的相同元素。这是考虑到了[0,0,0],[-1,-1,2]这类的情况
3.内层循环，定义两个指针，分别指向头（定值的下一个位置）和尾，判断这两个数的和是不是等于定值，若等于，则记录这三个数，并向中间移动头尾指针；若小于，则右移头指针；若大于，则左移尾指针。
4.注意，移动指针后，仍需判断头尾指针移动前后是否指向相同的元素，若是，则继续移动，这是为了防止出现重复的组
*/
class Solution {
public:
//为了使用STL中的排序
    static bool mySort(const int & num1,const int & num2){
        return num1 < num2;
    }
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int> > rv;
        sort(v.begin(),v.end(),mySort);
        int length = v.size();
        for(int i = 0;i < length;i++){
            while((i!=0)&&(v[i] == v[i-1])){
                i++;
                continue;
            }
            int j = i + 1,k=length - 1;
            while(j < length && k > j){
                vector<int> tv;
                if(v[j] + v[k] == -v[i]){
                    tv.push_back(v[i]);
                    tv.push_back(v[j]);
                    tv.push_back(v[k]);
                    rv.push_back(tv);
                    j++;
                    k--;
					while(j < k && v[j] == v[j-1]){
						j++;
					}
					while(j < k && v[k] == v[k+1]){
						k--;
					}
                }
                else if(v[j] + v[k] < -v[i]){
                    j++;
					while(j < k && v[j] == v[j-1]){
						j++;
					}
                }
                else{
                    k--;
					while(j < k && v[k] == v[k+1]){
						k--;
					}
                }
                
            }
        }
        return rv;
    }
};
[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]