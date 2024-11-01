var makeFancyString = function(s){
    let cnt = 0, ans = "";
    const n = s.length;
    for(let i = 0; i < n; ++i){
        cnt++;

        if(i && s[i] !== s[i - 1])
            cnt = 1;

        if(cnt < 3)
            ans += s[i];
    }

    return ans;
};