class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        map<int, vector<int>>frq;
        for( int i = 0; i < n; i++ )
            frq[nums[i]].push_back(i);

        set<vector<int>>ans;
        for( int i = 0; i < n - 2; i++ )
        {
            if( i && nums[i] == nums[i - 1] )
                continue;
            for( int j = i + 1; j < n - 1; j++ )
            {
                if( !frq[-1 * (nums[i] + nums[j])].empty() && frq[-1 * (nums[i] + nums[j])].back() > j )
                {
                    vector<int>vv;
                    vv.push_back(nums[i]);
                    vv.push_back(nums[j]);
                    vv.push_back(-1 * (nums[i] + nums[j]));
                    sort(vv.begin(), vv.end());
                    ans.insert(vv);
                }
            }
        }

        vector<vector<int>>anss;
        for( vector<int>i : ans )
            anss.push_back(i);

        return anss;
    }
};