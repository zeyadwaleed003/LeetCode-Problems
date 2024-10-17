class Solution 
{
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);

        int n = s.size();
        for( int i = 0; i < n; i++ )
        {
            char mx = s[i], idx;
            for( int j = i + 1; j < n; j++ )
                if( s[j] >= mx )
                    mx = s[j], idx = j;

            if( mx > s[i] )
            {
                char temp = s[i];
                s[i] = mx;
                s[idx] = temp;
                break;
            }
        }

        int ans = stoi(s);
        return ans;
    }
};