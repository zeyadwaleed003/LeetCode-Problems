func maxSum(nums []int) int {
    sum, mx := 0, -101
    m := make(map[int]bool)
    for _, v := range nums {
        if v > 0 && m[v] == false {
            sum += v
            m[v] = true
        }

        if mx < v {
            mx = v
        }
    }

    if sum == 0 {
        sum = mx
    }
    return sum
}