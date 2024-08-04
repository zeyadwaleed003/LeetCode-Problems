func majorityElement(nums []int) int {
    frq := make(map[int]int)
    n := len(nums)
    ans := 0
    for i := 0; i < n; i++ {
        frq[nums[i]]++
        if frq[nums[i]] > n / 2 {
            ans = nums[i]
        }
    }

    return ans
}