class Solution {
public:
 int ans = 0;
    void dfs(int node,int time,int score,int maxTime,vector<int>&values, vector<vector<pair<int,int>>>& graph,vector<int>& vis){
       
        if(node==0){
            ans=max(ans,score);
        }
        for(auto&[next,cost]:graph[node]){
            if(time+cost>maxTime){
                continue;
            }
              bool firstVisit=(vis[next]==0);
               vis[next]++;

                dfs(
                next,
                time + cost,
                score + (firstVisit ? values[next] : 0),
                maxTime,
                values,
                graph,
                vis
            );
            vis[next]--;
        }
    }


    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
      int n=values.size();

      vector<vector<pair<int,int>>>graph(n);

      for(auto &e:edges){
         
         int u=e[0];
         int v=e[1];
         int t=e[2];

         graph[u].push_back({v,t});
         graph[v].push_back({u,t});

      }
      vector<int>vis(n,0);

      vis[0]=1;
      dfs(0,0,values[0],maxTime,values,graph,vis);
      return ans;
        
    }
};