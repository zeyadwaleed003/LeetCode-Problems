class Solution {
public:
    int go(int last, int cur, int n)
    {
        if (cur == n)
            return 0;

        if (cur > n)
            return 10000;

        if (dp[last][cur] != -1)
            return dp[last][cur];

        int op1 = 10000, op2 = 10000;

        op1 = go(cur, cur + cur, n) + 2;
        op2 = go(last, cur + last, n) + ((last == 1 && cur == 1)? 2 : 1);

        return dp[last][cur] = min(op1, op2);
    }

    int minSteps(int n)
    {
        dp.assign(2005, vector<int>(2005, -1));
        return go(1, 1, n);
    }

private:
vector<vector<int>> dp;
};