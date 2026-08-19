class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return topoSort(numCourses,prerequisites);
    }

    bool topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj (V);
        vector<int> indegree(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        int cnt=0;
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        
        if(cnt==V) return true;
        return false;
    }
};