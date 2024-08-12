class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int l = 0, r = numbers.size() - 1, sum;
        while( l < r )
        {
            sum = numbers[l] + numbers[r];
            if( sum > target )
                r--;
            else if( sum < target )
                l++;
            else
                return {l + 1, r + 1};
        }

        return {};
    }
};