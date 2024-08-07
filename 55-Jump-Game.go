func canJump(nums []int) bool {
    l, r, n := 0, 0, len(nums)

    for r < n && l <= r {
        if r <= nums[l] + l {
            r = l + nums[l]
        }

        l++
    }

    if r >= n - 1 {
        return true
    }

    return false
}