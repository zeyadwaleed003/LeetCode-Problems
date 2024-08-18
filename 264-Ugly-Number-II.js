/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) 
{
    if( n == 1 )
        return 1;

    let p2 = 0, p3 = 0, p5 = 0;
    let ans = [n];
    ans[0] = 1;

    for( let i = 1; i < n; i++ )
    {
        ans[i] = Math.min(ans[p2] * 2, ans[p3] * 3, ans[p5] * 5);
        if( ans[i] == ans[p2] * 2 )
            p2++;

        if( ans[i] == ans[p3] * 3 )
            p3++;

        if( ans[i] == ans[p5] * 5 )
            p5++;
    }

    return ans[n - 1];
};