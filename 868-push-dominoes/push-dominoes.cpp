class Solution {
public:
    string pushDominoes(string domi) {
        string dom = 'L' + domi + 'R';
        int n = dom.size();

        int i=0;

        for(int j=1;j<n;j++){
            if(dom[j] == '.') continue;

            int cnt = j-i+1;

            if(cnt > 0){
                if(dom[i] == dom[j]){
                    for(int k=i+1;k<j;k++){
                        dom[k] = dom[i];
                    }
                }
                else if(dom[i] == 'R' && dom[j] == 'L'){
                    int l=i+1, r=j-1;

                    while(l<r){
                        dom[l] = 'R';
                        dom[r] = 'L';
                        l++;
                        r--;
                    }
                }
            }

            i=j;
        }

        return dom.substr(1, n-2);
    }

    // L...L -> every one will fall to the left
    // R...R-> ervery one will fall on the right hand side
    // L...R -> ervery one will keep standing
    // R...L -> for middle element it will stand as it is, now for the left of middle they will move towards right and rest will move toward left.

};