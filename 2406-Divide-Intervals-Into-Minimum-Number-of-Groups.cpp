class Solution {
public:
    int minGroups(vector<vector<int>>& intervals)
    {
        vector<int>partial(1e6 + 5, 0);

        int n = intervals.size();
        for( int i = 0; i < n; i++ )
        {
            partial[intervals[i][0]]++;
            partial[intervals[i][1] + 1]--;
        }

        for( int i = 1; i <= 1e6; i++ )
            partial[i] += partial[i - 1];

        return *max_element(partial.begin(), partial.end());
    }
};