class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int frqS[26] = {}, frqT[26] = {};
        for( char i : s )
            frqS[i - 'a']++;

        for( char i : t )
            frqT[i - 'a']++;

        for( char i : t )
        {
            if( !frqS[i - 'a'] )
                return false;

            frqS[i - 'a']--;
        }

        for( char i : s )
        {
            if( !frqT[i - 'a'] )
                return false;

            frqT[i - 'a']--;
        }

        return true;
    }
};