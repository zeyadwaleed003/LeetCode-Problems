let dp = [];
let go = ( steps, n ) => {
    if( steps > n )
        return 0;

    if( steps == n )
        return 1;

    if( dp[steps] != -1 )
        return dp[steps];

    let op1 = go( steps + 1, n );
    let op2 = go( steps + 2, n );

    return dp[steps] = op1 + op2;
}

var climbStairs = (n) => {
    for( let i = 0; i < 55; i++ )
        dp[i] = -1;

    return go(0, n);
}