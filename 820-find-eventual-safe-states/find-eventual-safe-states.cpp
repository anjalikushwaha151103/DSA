class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adjr(n);
        vector<int> indegree(n,0);

        //reverse edges and calculate indegree
        for(int i=0;i<n;i++){
            for(int it:graph[i]){
                adjr[it].push_back(i);
                indegree[i]++;
            }
        }

        //push terminal nodes( indegree=0) into queue
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        //toposort (bfs)
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjr[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;


    }
};