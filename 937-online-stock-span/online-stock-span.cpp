class StockSpanner {
public:
    stack<int> st;
    stack <int> span;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int i=1;
        while(!st.empty() && st.top()<=price){
            i+=span.top();
            st.pop();
            span.pop();
            
        }
        st.push(price);
        span.push(i);
        return span.top();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */