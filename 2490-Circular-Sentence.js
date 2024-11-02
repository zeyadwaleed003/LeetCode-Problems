var isCircularSentence = function(sentence) {
    const n = sentence.length;
    for(let i = 0; i < n; ++i){
        if(sentence[i] === ' ' && sentence[i - 1] !== sentence[i + 1])
            return false;
    }

    if(sentence[n - 1] !== sentence[0])
        return false;
    return true;
};