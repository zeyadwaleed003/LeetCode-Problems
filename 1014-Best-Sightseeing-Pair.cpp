class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, c = 0;
        for( int i : values ) {
            ans = max(ans, c + i);
            c = max(c, i);
            --c;
        }

        return ans;
    }
};