class Solution {
public:


    bool detect(int node,int col,vector<vector<int>>& graph, vector<int> &visited){

        visited[node]=col;

        for(int it:graph[node]){
            if(visited[it]==-1){
                if(detect(it,!col,graph,visited)==false) return false;
            }else{
                if(visited[node]==visited[it]) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(detect(i,0,graph,visited)==false) return false;
            }
        }
        return true;
    }
};