var longestConsecutive = function(nums) {
    let st = new Set();
    nums.forEach(val => st.add(val));
    let arr = Array.from(st).sort((a, b) => a - b);

    let mx = 0, cur = 0, prev = arr[0] - 1;
    arr.forEach(val => {
        if( val == prev + 1 )
            cur++;
        else
            mx = Math.max(mx, cur), cur = 1;
        prev = val;
    });

    mx = Math.max(mx, cur);
    return mx;
};