/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
剧透一波，用卡特兰数来解决！！
卡特兰数的特点：G(n) = G(1)*G(n-1)+G(2)*G(n-2)+...+G(n-1)*G(1);
卡特兰数还有一个递推公式是：C(n+1) = 2(2n+1)*C(n)/(n+2);
C(n) = (2n,n)-(2n,n+1);括号中代表组合数

这个问题上，我们令G(n)来表示当节点数为n时，不同的BST种数；
令F(i,n)来表示以i为根节点的BST的个数，其中i的取值范围是[1,n]。那么G(n)=F(1,n)+F(2,n)+...+F(n,n);
由于BST的特性，以i为根节点的左右子树也是BST，且左子树上有i-1个节点，右子树上有n-i个节点（排除根节点）。
那么我们可以得到，F(i,n)=G(i-1)*G(n-i)。
代入，即有G(n) = G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0);
令G(0)=G(1)=1，我们就可以得到G(n)了。

*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            for(int j = 0;j<i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
/*
当然也可以直接使用递推公式 C(n+1)=2(2n+1)*C(n)/(n+2);
*/
class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i<=n;i++){
            dp[i] = (4*i-2)*dp[i-1]/(i+1);
        }
        return dp[n];
    }
};
