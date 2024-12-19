var maxChunksToSorted = function(arr) {
    let sum1 = 0, sum2 = 0, ans = 0, n = arr.length;
    for(let i = 0; i < arr.length; ++i){
        sum1 += i;
        sum2 += arr[i];
        if(sum1 === sum2)
            ++ans;
    }    

    return ans;
};