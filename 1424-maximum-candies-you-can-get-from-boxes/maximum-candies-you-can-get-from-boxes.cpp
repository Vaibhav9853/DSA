class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = candies.size();
        vector<int> curr(n,0);
        vector<int> vis(n, 0);
        queue<int> q;

        for(auto it:initialBoxes){
            curr[it] = 1;
            if(status[it]) q.push(it);
        }

        int ans = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();

            if(vis[x]) continue;
            
            vis[x] = 1;
            ans += candies[x];

            for(auto it: keys[x]){
                status[it] = 1;

                if(curr[it] && !vis[it]){
                    q.push(it);
                }
            }

            for(auto it:containedBoxes[x]){
                curr[it] = 1;

                if(status[it] && !vis[it]){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};