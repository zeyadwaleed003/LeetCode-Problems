class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        int MOD = 1e9 + 7;
        vector<int>ans;

        int sum = 0;
        for( int i = 0; i < n; i++ )
        {
            sum = 0;
            for( int j = i; j < n; j++ )
            {
                sum += (nums[j] % MOD);
                sum %= MOD;
                ans.push_back(sum);
            }
        }

        sort(ans.begin(), ans.end());
        left--, right--;

        int res = 0;
        for( int i = left; i <= right; i++ )
        {
            res += (ans[i] % MOD);
            res %= MOD;
        }

        return res;
    }
};