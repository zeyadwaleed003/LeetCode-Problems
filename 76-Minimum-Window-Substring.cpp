class Solution {
public:
    string minWindow( string s, string t )
    {
        map<char,int>m, mm;
    set<char>ss, tt;
    for( int i = 0; i < t.size(); i++ )
    {
        if( !tt.count(t[i]) )
            tt.insert(t[i]);
        m[t[i]]++;
        mm[t[i]]++;
    }
    int r = 0, l = 0;
    string ans = \\;
    int mn = (int)1e9;
    while( r < s.size() )
    {
        while( r < s.size() && ss.size() != tt.size() )
        {
            if( m[s[r]] )
            {
                mm[s[r]]--;
                if( mm[s[r]] == 0 )
                    ss.insert(s[r]);
            }
            r++;
        }
        while( ss.size() == tt.size() )
        {
            mm[s[l]]++;
            if( mm[s[l]] > 0 )
            {
                ss.erase(s[l]);
                string test = s.substr(l, r - l);
                if( (int)test.size() < mn )
                    mn = (int)test.size(), ans = test;
            }
            l++;
        }
    }
    return ans;
    }
};