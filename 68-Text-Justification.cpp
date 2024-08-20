class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string>v;
        int spaces = 0, totChars = 0, l = 0, r = 0;
        while( r < words.size() )
        {
            if( totChars + spaces + words[r].size() > maxWidth )
            {
                int avail = maxWidth - totChars;
                if( spaces > 1 )
                    spaces -= 1;
                int space = avail / spaces;
                avail %= spaces;

                string s;
                for( int i = l; i < r; i++ )
                {
                    s += words[i];

                    int cnt = 0;
                    while( cnt++ < space && spaces )
                        s += ' ';
                    spaces--;

                    if( avail > 0 )
                        avail--, s += ' ';
                }

                v.push_back(s);
                spaces = 0;
                totChars = 0;
                l = r;
            }

            spaces++;
            totChars += words[r].size();
            r++;
        }

        string s;
        for( int i = l; i < r; i++ )
        {
            s += words[i];
            if( i + 1 != r )
                s += ' ';
        }

        while( s.size() < maxWidth )
            s += ' ';
        v.push_back(s);
        return v;
    }
};