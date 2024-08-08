func productExceptSelf(nums []int) []int {
    pr, zero := 1, 0
    for i := 0; i < len(nums); i++ {
        if nums[i] != 0 {
            pr *= nums[i]
        }

        if nums[i] == 0 {
            zero++
        }
    }

    ans := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        if nums[i] == 0 {
            if zero > 1 {
                ans[i] = 0
            } else {
                ans[i] = pr
            }
        } else {
            if zero > 0 {
                ans[i] = 0
            } else {
                ans[i] = pr / nums[i]
            }
        }
    }

    return ans
}