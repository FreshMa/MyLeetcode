/*
069 Sqrt(x)
Implement int sqrt(int x).
Compute and return the square root of x.
采用二分法，至于牛顿迭代，还是下次再说吧
*/
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int h = x;
        int ans;

        while(l<=h)
        {
            int m = (l+h) / 2;

            int t1 = m * m - x;
            int t2 = (m+1) * (m+1) - x;
            //考虑边界情况，46341的平方刚好超出INT_MAX，所以当发现m大于46340时，重置上下边界，使得m的值刚好取到46340
            if(m>46340)
            {
                l = 0;
                h = 92680;
                continue;
            }
            //由于返回值和参数都是int，所以使用这种判断方法，m^2<x<(m+1)^2时，取m
            if(t1 <= 0 && t2 > 0)
            {
                ans = m;
                break;
            }
            //(m+1)^2=x时取m+1
            else if(t2 == 0)
            {
                ans = m+1;
                break;
            }
            //m^2>x，减小上界h
            else if(t1 > 0)
            {
                h = m;
            }
            //(m+1)^2>x，增大下界l
            else if(t2 < 0)
            {
                l = m;
            }
        }
        return ans;
    }
};
