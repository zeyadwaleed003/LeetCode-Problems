var minChanges = function(s) {
    let cnt = 0;
    const n = s.length;
    for(let i = 0; i < n; i += 2)
    if(s[i] !== s[i + 1])
        cnt++;
    
    return cnt;
};