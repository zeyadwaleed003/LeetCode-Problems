class Solution {
public:
    char findKthBit(int n, int k) 
    {
        vector<string>s;
        s.push_back("0");
        while( s.size() < 20 )
        {
            string last = s.back();
            for( int i = 0; i < last.size(); i++ )
                last[i] = last[i] == '1'? '0' : '1';

            reverse(last.begin(), last.end());
            s.push_back(s.back() + "1" + last);
        }

        return s.back()[k - 1];
    }
};