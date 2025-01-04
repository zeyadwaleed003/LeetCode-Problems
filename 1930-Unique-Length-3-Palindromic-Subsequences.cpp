class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int sz = s.size();

        map<char, vector<int>>m;
        for( int i = 0; i < sz; ++i )
            m[s[i]].push_back(i);

        int ans = 0;
        for( char i = 'a'; i <= 'z' ; ++i ){
            if( m[i].size() >= 2 ){
                set<char>st;
                for( int ii = m[i][0] + 1; ii < m[i][m[i].size() - 1]; ++ii )
                    st.insert(s[ii]);

                ans += st.size();
            }
        }

        return ans;
    }
};