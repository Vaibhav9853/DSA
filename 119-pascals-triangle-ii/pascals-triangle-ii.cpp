class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> ans;
        ans.push_back(1);
        long long x = 1;

        for(int i=0;i<r;i++){
            x = (x*(r-i)) / (i+1);
            ans.push_back((int)x);
        }

        return ans;
    }
};