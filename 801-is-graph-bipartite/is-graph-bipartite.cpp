class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);

        int color=0;

        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(dfs(i,graph,visited,color)==false) return false;
            }
        }
        return true;

    }

    bool dfs(int node,vector<vector<int>>& graph, vector<int> &visited,int color){
        visited[node]=color;
        for(auto it:graph[node]){
            if(visited[it]==-1){
                if(!dfs(it,graph,visited,!color)) return false;
            }else if(visited[it]==color) return false;
        }
        return true;
    }
};