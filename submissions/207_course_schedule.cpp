/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
and to take course 0 you should also have finished course 1. So it is impossible.
*/

/*
将所需课程抽象成有向图，对其使用拓扑排序，看能否生成合法序列。
拓扑排序流程如下：
1. 找到所有入度为零的点加到队列中
2. 当队列非空：队列中每一个结点v，以该节点为起点的边(v,v1)，减去v1的入度；
3. 如果v1的入度为零，加入队列，重复2步骤
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> indegree;
		int cnt = 0;
        
        queue<int> que;
        for(auto it:prerequisites){
			edge[it.second].push_back(it.first);
			indegree[it.first]++;
        }
		for(int i = 0;i < numCourses; ++i){
			if(indegree[i] == 0)
				que.push(i);
		}
		while(!que.empty()){
			int ele = que.front();
			cnt++;
			que.pop();
			for(auto node:edge[ele]){
				if(--indegree[node] == 0)
					que.push(node);
			}
		}
		return cnt == numCourses;
    }
};
