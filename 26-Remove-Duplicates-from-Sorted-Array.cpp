class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>frq;
        bool good[nums.size()];
        memset(good, 1, sizeof good);
        for( int i = 0; i < nums.size(); i++ )
        {
            if( frq[nums[i]] )
                good[i] = 0;

            frq[nums[i]]++;
        }

        vector<int>arr = nums;
        nums.clear();
        for( int i = 0; i < arr.size(); i++ )
        {
            if( good[i] )
                nums.push_back(nums[i]);
        }

        return nums.size();
    }
};