class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] == val )
                nums[i] = 1001;
        }

        sort(nums.begin(), nums.end());

        int ans = 0;
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] != 1001 )
                ans++;
        }

        return ans;
    }
};