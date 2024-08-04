class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int cnt = 0, n = nums.size();

        vector<pair<int,int>>pos;
        map<int, int>frq;
        for( int i = 0; i < n; i++ )
        {
            if( frq[nums[i]] >= 2 )
            {
                cnt++;
                continue;
            }

            pos.push_back({i - cnt, nums[i]});
            frq[nums[i]]++;
        }

        sort(pos.begin(), pos.end());
        nums.clear();

        for( int i = 0; i < pos.size(); i++ )
            nums.push_back(pos[i].second);

        return pos.size();
    }
};