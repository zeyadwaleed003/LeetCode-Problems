class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int l = 0, r = height.size() - 1, ans = 0;
        while( l < r )
        {
            ans = max(ans, ( r - l ) * min(height[l], height[r]));
            height[l] < height[r]? l++ : r--;
        }

        return ans;
    }
};