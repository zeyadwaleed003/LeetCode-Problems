var longestSquareStreak = function(nums) {
    let frq = [];
    for(let i = 0; i < 1e5 + 5; i++)
        frq.push(0);

    nums.forEach(val => frq[val]++);

    let sq = [];
    for(let i = 2; i * i <= 1e5 + 5; i++)
        sq.push(i * i);

    let ans = 1, cnt = 1;
    sq.forEach(val => {
        let value = val;
        while(value <= 1e5 && frq[value] && frq[Math.floor(Math.sqrt(value))])
            cnt++, sq.pop(value), value *= value;
        ans = Math.max(ans, cnt);
        cnt = 1;
    });

    if(ans == 1)
        ans = -1;
    return ans;
};