var addBinary = function(a, b) 
{
    if( a.length < b.length )
    {
        a = a.split('').reverse().join('');

        while( a.length < b.length )
            a += '0';

        a = a.split('').reverse().join('');
    }

    if( a.length > b.length )
    {
        b = b.split('').reverse().join('');

        // console.log(b);
        while( b.length < a.length )
            b += '0';

        b = b.split('').reverse().join('');
    }

    // console.log(a, b);

    let one = 0, ans = '';
    for( let i = b.length - 1; i >= 0; i-- )
    {
        ans += one ^ +a[i] ^ +b[i];
        one = (one & +b[i]) || (one & +a[i]) || (+a[i] & +b[i]);
        // console.log(one);
    }

    if( one )
        ans += '1';

    ans = ans.split('').reverse().join('');
    return ans
};