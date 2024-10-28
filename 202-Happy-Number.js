var isHappy = function(n) {
    let frq = [];
    for(let i = 0; i < 100000; i++) frq[i] = 0;

    let num = n;
    while(true){
        if(num == 1)
            return true;

        if(frq[num] > 0)
            return false;
        frq[num]++;

        let sum = 0;
        while(num){
            let d = Math.floor(num % 10);
            d *= d;
            sum += d;
            num = Math.floor(num / 10);
        }

        num = sum;
    }

    return false;
};
