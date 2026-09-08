class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n = s.size();

        int i=0,j=0;
        int max_len = 0;
        while(j<n && i<=j){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            max_len = max(max_len, j-i+1);
            j++;
        }
        return max_len;
    }
};