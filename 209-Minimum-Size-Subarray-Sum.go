func minSubArrayLen(target int, nums []int) int {
    l, r, sum, n, ans := 0, 0, 0, len(nums), int(1e9)
    sum += nums[0]
    for l <= r && r < n {
        if sum >= target {
            ans = min(ans, r - l + 1)
            sum -= nums[l]
            l++
        } else {
            r++
            if r < n {
                sum += nums[r]
            } else { 
                break
            }
        }
    }

    if ans == int(1e9) {
        return 0
    }

    return ans
}