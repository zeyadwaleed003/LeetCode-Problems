class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int n = s.size();
        vector<int>indexS(200, -1);
        vector<int>indexT(200, -1);

        for( int i = 0; i < n; i++ )
        {
            if( indexS[s[i]] != indexT[t[i]] )
                return false;

            indexS[s[i]] = i + 1;
            indexT[t[i]] = i + 1;
        }
        return true;
    }
};