class Solution {
    public:
    int clumsy(int n){
        stack<int> s;
        s.push(n);
        int op = 0;

        for(int i = n - 1; i >= 1; i--){
            if(op == 0){
                int val = s.top();
                s.pop();
                s.push(val * i);
                }
                else if(op == 1){
                    int val = s.top();
                    s.pop();
                    s.push(val / i);
                    }
                    else if(op == 2){
                        s.push(i);
                    }
                    else if(op == 3){
                        s.push(-i);
                    }

                    op++;
                    if(op == 4){
                        op = 0;
                    }
                    }

                    int ans = 0;
                    while(!s.empty()){
                        ans = ans + s.top();
                        s.pop();
                        }

                        return ans;
                        }
                        };