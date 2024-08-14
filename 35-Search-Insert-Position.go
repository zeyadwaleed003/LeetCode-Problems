func searchInsert(nums []int, target int) int {
    l, r:= 0, len(nums) - 1
    var mid int
    for l <= r {
        mid = ( l + r ) / 2
        if nums[mid] >= target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }

    return l
}