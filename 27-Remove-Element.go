func removeElement(nums []int, val int) int {
    for i := 0; i < len(nums); i++ {
        if nums[i] == val {
            nums[i] = 1001
        }
    }

    sort.Ints(nums);
    ans := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] != 1001 {
            ans++
        }
    }

    return ans;
}