/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*
这种寻找可行解的题目可以考虑深搜，即dfs。
依次从每个字符出发，如果该字符是要寻找的字符，则继续向四个方向搜索，同时注意
标记在该次寻找中已经过的路径，已经过的点不再搜索。
直到搜索到的字符串长度等于要寻找的字符串，返回true。否则返回false
*/

class Solution {
public:
    /*
    @param row,col:搜索路径上的当前点
    @param word:要寻找的单词
    @param pos:当前搜索word的第几个字符
    @param M,N：board的边界
    @param visit:访问数组，不使用引用会超时。也可以考虑每次搜索时将当前字符记录下来，然后在进行下一步搜索时将其修改为'*'，
    搜索完成之后再改回来。这样可以极大地降低空间复杂度。
    */
    bool helper(vector<vector<char>> &board,int row,int col,string& word,int pos,int M,int N,int slen,vector<vector<bool>> &visit){
        char cur = board[row][col];
        bool res=false;
        //如果当前搜索位置字符不是word中pos位的字符，或者该字符已经访问过，直接返回false
        if (cur!=word[pos]||visit[row][col]) return false;
        //访问标记置为真
        visit[row][col]=true;
        //如果已经到达word的最后一个字符，返回真
        if(pos==slen-1) return true;
        //依次向四个方向访问，只要有一个方向上找到可行解，就不再向其他方向寻找
        if(row>0) res=helper(board,row-1,col,word,pos+1,M,N,slen,visit);
        if(!res&&row<M-1) res=helper(board,row+1,col,word,pos+1,M,N,slen,visit);
        if(!res&&col>0) res=helper(board,row,col-1,word,pos+1,M,N,slen,visit);
        if(!res&&col<N-1) res=helper(board,row,col+1,word,pos+1,M,N,slen,visit);
        //重置访问标记为假，为了不影响下一轮的搜索
        visit[row][col]=false;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rowlen = board.size();
        int collen = board[0].size();
        vector<vector<bool>> visit(rowlen,vector<bool>(collen,false));
        int slen = word.length();
        //依次以棋盘中每一个点为起点搜索，找到一个可行解即返回真
        for(int i = 0;i<rowlen;i++){
            for(int j = 0;j<collen;j++){
                if(helper(board,i,j,word,0,rowlen,collen,slen,visit))
                    return true;
            }
        }
        return false;

    }
};
