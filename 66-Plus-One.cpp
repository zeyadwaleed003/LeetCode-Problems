class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        bool ok = false;
        vector<int>ans;
        for( int i = digits.size() - 1; i >= 0; i-- )
        {
            if( ok )
                ans.push_back(digits[i]);
            else if( digits[i] == 9 )
                ans.push_back(0);
            else
            {
                ans.push_back(digits[i] + 1);
                ok = true;
            }
        }    

        if( !ok )
            ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};