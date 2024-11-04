var compressedString = function(word) {
    const n = word.length;
    let ans = "", cnt = 1;
    for(let i = 1; i < n; ++i){
        if(word[i] !== word[i - 1] || cnt === 9){
            ans += `${cnt}${word[i - 1]}`;
            cnt = 0;
        }

        cnt++;
    }

    ans += `${cnt}${word[n - 1]}`;
    return ans;
};