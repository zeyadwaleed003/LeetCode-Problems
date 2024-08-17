class Solution {
public:
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        string r = s;
        reverse(r.begin(), r.end());
        cout << s << ' ' << r;
        if( s == r )
            return true;
        return false;
    }
};