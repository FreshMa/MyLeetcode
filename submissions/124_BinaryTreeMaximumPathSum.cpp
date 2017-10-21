/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the 
parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

/*
discuss中的思路：
1. 使用变量maxValue记录最大值；
2. 使用递归，参数为结点node，如果结点为空，返回0；否则对其左右子树调用该调用函数，并将返回值与0比较，记录较大值（负值对结果无贡献)，
分别记作left和right；
3. 将left和right相加，再加上结点值，用该值与maxValue比较，适当更新maxValue；
4. 该函数返回值为max(left,right)+node->val；原因是maxValue记录的是包含该结点的一个完整路径上的最大值，即同时包含该节点以及该节点的左右子树；
而还有一种情况是最终路径没有同时包含该结点的左右子树，那么此时最终路径只包含了该节点以及它的(部分)左子树或(部分)右子树，返回该值以便调用者扩展路径。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxVal = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxRoot(root);
        return maxVal;
    }
    
    int maxRoot(TreeNode* node){
        if(!node) return 0;
        int left = max(0,maxRoot(node->left));
        int right = max(0,maxRoot(node->right));
        maxVal = max(maxVal, left+right+node->val);
        return max(left, right)+node->val;
    }
};
