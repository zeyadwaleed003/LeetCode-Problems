class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ans = 0, mn = 1e5, n = prices.size();
        set<int, greater<>>s;
        map<int,int>frq;

        for( int i = 0; i < n; i++ )
            s.insert(prices[i]), frq[prices[i]]++;

        for( int i = 0; i < n; i++ )
        {
            frq[prices[i]]--;
            if( !frq[prices[i]] )
                s.erase(prices[i]);
            mn = min(mn, prices[i]);

            ans = max(ans, *s.begin() - mn);
        }

        return ans;
    }
};