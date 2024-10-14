class Solution {
public:
    int n;
    int dp[201][201];
    int go( int i, int lastIdx, vector<vector<int>>& triangle )
    {
        if( i == n )
            return 0; 

        if( dp[i][lastIdx] != -1 )
            return dp[i][lastIdx];
        
        int val = triangle[i][lastIdx];
        int op1 = go( i + 1, lastIdx, triangle );
        int op2 = go( i + 1, lastIdx + 1, triangle );

        return dp[i][lastIdx] = min(op1, op2) + val;
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        n = triangle.size();
        memset(dp, -1, sizeof dp);
        return go(0, 0, triangle);
    }
};