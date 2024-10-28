var containsNearbyDuplicate = function(nums, k) {
    let m = new Map(), l = 0, cnt = 0;
    const n = nums.length;
    for(let i = 0; i < n; i++){
        if(cnt > k)
            m.set(nums[l], m.get(nums[l++]) - 1);

        if(m.get(nums[i]) > 0)
            return true;

        m.set(nums[i], !m.has(nums[i])? 1 : m.get(nums[i]) + 1);
        cnt++;
    }

    return false;
};