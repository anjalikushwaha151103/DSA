class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return topoSort(numCourses,prerequisites);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj (V);
        vector<int> indegree(V);
        for(auto it:edges){
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        vector<int> ans;
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(ans.size()!=V) return {};
        return ans;
    }
};