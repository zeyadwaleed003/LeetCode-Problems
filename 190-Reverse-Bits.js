var reverseBits = function(n) 
{
    let ans = 0, bits = 32;
    while( bits-- )
    {
        ans *= 2;
        ans += n & 1;
        n >>= 1;
    }

    return ans;
};