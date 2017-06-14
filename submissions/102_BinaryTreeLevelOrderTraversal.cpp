/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/*
二叉树的层次遍历，需要使用辅助队列。在开始添加下一层节点之前保存当前队列大小，
该大小即为该层节点的个数。依次访问这些节点即可。
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> ret;
    if(!root) return ret;
    q.push(root);
    while(!q.empty()){
      int size = q.size();
      vector<int> vec;
      for(int i = 0;i<size;i++){
        TreeNode *tmp = q.front();
        q.pop();
        vec.push_back(tmp->val);
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
      }
      ret.push_back(vec);
    }
    return ret;
  }
};
