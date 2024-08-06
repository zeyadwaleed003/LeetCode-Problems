class Solution {
public:
    int minimumPushes(string word) 
    {
        vector<int>frq(26, 0);
        set<char>s;
        int mx = 0;
        for( char i : word )
        {
            frq[i - 'a']++;
            mx = max(frq[i - 'a'], mx);
            s.insert(i);
        }

        priority_queue<int>pq;
        for( char i : word )
            pq.push(frq[i - 'a']);

        int idx = 1, mul = 1, ans = 0;
        vector<bool>vis(26, 0);
        while( !pq.empty() )
        {
            int top = pq.top();
            pq.pop();

            for( char c : s )
            {
                if( idx == 9 )
                    mul++, idx = 1;
            
                if( frq[c - 'a'] == top && vis[c - 'a'] == 0 )
                    ans += frq[c - 'a'] * mul, vis[c - 'a'] = 1, idx++, s.erase(c);
            }
        }

        return ans;
    }
};