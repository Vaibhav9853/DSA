class StockSpanner {
    stack<int> st;
    vector<int> v;
    int i=0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        v.push_back(price);
        while(!st.empty() && v[st.top()] <= price){
            st.pop();
        }
        int ans;
        if(st.empty()) ans = i+1;
        else{
            ans = i-st.top();
        }
        st.push(i);
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */