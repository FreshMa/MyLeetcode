/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

/*
N皇后问题是一个经典的深搜问题，我们用深搜+剪枝来解决。
使用一个一维数组来记录每一行上皇后出现的列数，如Q[i]代表第i行的皇后的位置。
一行一行的放置，如果该行找到可行位置，就试探下一行，如此一直到最后一行，如果也
找到了位置，说明该问题有解，保存这个时候的解。
如果在某行没有找到解，就退出该分支的搜索。
*/
/*
052问题和这个一样，不过只需要返回解的数量就行了。所以代码量比较少
只需要定义一个全局变量，找到可行解的时候递增即可。最后返回该变量。
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> res;
      vector<int> Q(n,-1);
      dfs(res,Q,0);
      return res;
    }

    void dfs(vector<vector<string>> &res,vector<int> &Q,int row){
      const int N=Q.size();
      //当前行等于行数时，说明最后一行也已经搜索过了[0,N-1]，保存此时的解
      //每一个解，即棋盘是vector<string>类型的，vector中的元素是一个字符串，代表一行
      //每一行中除皇后位置外都是'.'，而皇后位置又保存在Q中
      if(row==N){
        //vec代表该棋盘
        vector<string> vec;
        //处理每一行
        for(int i = 0;i<N;i++){
          string str(N,'.');
          str[Q[i]]='Q';
          vec.push_back(str);
        }
        //添加该解
        res.push_back(vec);
        return;
      }

      //尚未到达终点，继续搜索，试探该行每一个位置
      for(int i = 0;i<N;i++){
        //如果不能放置，试探下一个位置
        if(!isValid(Q,row,i)) continue;
        //如果可以放置，记录该位置，试探下一行
        Q[row] = i;
        dfs(res,Q,row+1);
      }
    }

    //判断row行col列能否放置皇后
    bool isValid(vector<int> &Q,int row,int col){
      //分别判断是否与已放置好的row行冲突
      for(int i = 0;i<row;i++){
        //如果该列上已经放置了皇后，不能放置
        if(Q[i]==col) return false;
        //如果对角线上已经放置了皇后，不能放置。考虑该位置与每一行上皇后的行，列距离是否相等，
        //如果相等说明以二者为对顶点构成了正方形，即在一条对角线上
        if(abs(i-row)==abs(Q[i]-col)) return false;
      }
      return true;
    }
};
