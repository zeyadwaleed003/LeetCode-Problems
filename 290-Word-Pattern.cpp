class Solution {
public:
   bool wordPattern(string pattern, string s)
    {
        map<string, char>m;
        map<string, bool>vis;
        map<char,string>mm;
        for( char i = 'a'; i <= 'z'; i++ )
            mm[i] = \\;

        string word = \\;
        int n = s.size(), j = 0, words = 0;
        for( int i = 0; i < n; i++ )
        {
            if( s[i] == ' ' )
            {
                words++;
                if( vis[word] && m[word] != pattern[j] )
                    return false;
                
                if( mm[pattern[j]] != word && mm[pattern[j]] != \\ )
                    return false;

                vis[word] = 1;
                m[word] = pattern[j];
                mm[pattern[j]] = word;
                word = \\, ++j;
            }
            else
                word += s[i];
        }

        if( vis[word] && m[word] != pattern[j] )
            return false;

        if( mm[pattern[j]] != word && mm[pattern[j]] != \\ )
            return false;

        if( pattern.size() - 1 != words )
            return false;
        return true;
    }
};