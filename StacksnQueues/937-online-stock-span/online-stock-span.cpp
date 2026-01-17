class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<int> stk;
        vector<int> stocks;
    
    int next(int price) {
        // find last greater element
        stocks.push_back(price);
        int i = stocks.size() -1;
        int ans= 0;
        while(i > -1 && stocks[i] <= price){
            ans++;
            i--;
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


//  span = the number of days since the stock was last high than the current prices

// 