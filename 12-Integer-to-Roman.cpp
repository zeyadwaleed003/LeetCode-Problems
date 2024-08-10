class Solution {
public:
    string intToRoman(int num) 
    {
        int cur = 1;
        string ans;
        while( num )
        {
            int dig = num % 10;
            num /= 10;

            dig *= cur;
            cur *= 10;

            string s = \\;
            if( dig == 4 )
                dig -= 4, s += \IV\;
            else if( dig == 9 )
                dig -= 9, s += \IX\;
            else if( dig == 40 )
                dig -= 40, s += \XL\;
            else if( dig == 90 )
                dig -= 90, s += \XC\;
            else if( dig == 400 )
                dig -= 400, s += \CD\;
            else if( dig == 900 )
                dig -= 900, s += \CM\;

            while( dig >= 1000 )
                dig -= 1000, s += \M\;
            while( dig >= 500 )
                dig -= 500, s += \D\;
            while( dig >= 100 )
                dig -= 100, s += \C\;
            while( dig >= 50 )
                dig -= 50, s += \L\;
            while( dig >= 10 )
                dig -= 10, s += \X\;
            while( dig >= 5 )
                dig -= 5, s += \V\;
            while( dig >= 1 )
                dig -= 1, s += \I\;

            reverse(s.begin(), s.end());
            ans += s;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};