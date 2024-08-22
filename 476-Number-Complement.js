var findComplement = function(num) {
    let binaryNum = num.toString(2);

    let ans = [];
    for( let i = 0; i < binaryNum.length; i++ )
        ans.push(parseInt(binaryNum[i]) ^ 1);

    let anss = ans.join('');
    return parseInt(anss, 2);
};