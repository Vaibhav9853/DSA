class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i=0;i<n;i++){
           if(!st.empty() && (st.top() > 0 && asteroids[i] < 0)){
            int tk = 1;
            while(!st.empty() && st.top() > 0){
                if(st.top() < abs(asteroids[i])) st.pop();
                else if(st.top() == abs(asteroids[i])) {tk=0; st.pop(); break;}
                else {tk=0; break;}
            }
            if(tk == 1) st.push(asteroids[i]);
           }
           else{
            st.push(asteroids[i]);
           }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};