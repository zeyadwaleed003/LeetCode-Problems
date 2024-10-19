class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, vector<int>>m;
        int idx = 0;
        for( int i : nums )
           m[i].push_back(idx++);

        vector<int>ans;
        for( int i = 0; i < nums.size(); i++ )
        {
            if( m[target - nums[i]].size() )
            {
                if( target - nums[i] != nums[i] )
                {
                    ans.push_back(i);
                    ans.push_back(m[target - nums[i]][0]);
                    break;
                }
                else
                {
                    if( m[target - nums[i]].size() > 1 )
                    {
                        ans.push_back(m[target - nums[i]][0]);
                        ans.push_back(m[target - nums[i]][1]);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};