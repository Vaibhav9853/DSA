class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;

        int n = word1.size();
        vector<int> freq(26,0);
        vector<int> freq2(26,0);
        unordered_map<int, int> mp;

        for(char ch:word1){
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            mp[freq[i]]++;
        }
        for(char ch:word2){
            freq2[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            mp[freq2[i]]--;
        }

        for(auto it:mp){
            if(it.second != 0){
                return false;
            }
        }

        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                if(freq2[i] == 0) return false;
            }
            else if(freq2[i] > 0){
                if(freq[i] == 0) return false;
            }
        }

        return true;
    }
};