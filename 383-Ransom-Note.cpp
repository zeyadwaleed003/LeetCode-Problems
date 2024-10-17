class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int frq[26] = {};
        for( char i : magazine ) frq[i - 'a']++;;
        for( char i : ransomNote )
            if( !frq[i - 'a']-- )
                return false;

        return true;
    }
};