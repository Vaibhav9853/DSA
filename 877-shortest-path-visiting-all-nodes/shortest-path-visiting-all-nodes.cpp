class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all = (1<<n) - 1;

        vector<vector<int>> vis(n, vector<int> (all+1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push({i, (1<<i)});
            vis[i][(1<<i)] = 1;
        }

        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [node, mask] = q.front();
                q.pop();

                if(mask == all) return ans;

                for(auto &it:graph[node]){
                    int new_mask = mask | (1<<it);
                    if(!vis[it][new_mask]){
                        q.push({it, new_mask});
                        vis[it][new_mask] = 1;
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};