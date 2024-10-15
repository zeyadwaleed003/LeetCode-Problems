class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long cnt = 0, ans = 0;
        for( char i : s )
            i == '1'? cnt++ : ans += cnt;

        return ans;
    }
};