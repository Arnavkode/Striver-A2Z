class StockSpanner {
public:
    StockSpanner() {
        
    }
        stack<pair<int, int>> stk;
    
    int next(int price) {
        // find last greater element
        int currentSpan = 1;
        while(!stk.empty() && stk.top().first <= price){
            currentSpan += stk.top().second;
            stk.pop();


        }
        stk.push({price, currentSpan});
        return currentSpan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


//  span = the number of days since the stock was last high than the current prices

// brute force is ass
// all i need to do is, check if the current element is less than the 