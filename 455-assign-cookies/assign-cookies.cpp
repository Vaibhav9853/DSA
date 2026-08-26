class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0,j=0;
        int cnt = 0;

        while(j<g.size() && i<s.size()){
            if(s[i] >= g[j]){
                j++;
                i++;
                cnt++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};
